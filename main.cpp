#include "ControlElement.hpp"

#include <memory>

#include <map>
#include <string>

#include "InstructionRegistry.hpp"
#include "InstructionMap.hpp"

#include "MockFiddler.hpp"

#include "MockFiddlerView.hpp"
#include "FiddlerViewModes.hpp"
#include "FiddlerFlagView.hpp"
#include "FiddlerInterpretationView.hpp"

#include "InstructionWrapper.hpp"

#include "NumberStringParser.hpp"
#include "StringNumberConverter.hpp"

#include "FiddlerCommands/FiddlerMath.hpp"

#include "FiddlerCommands/FiddlerLogic.hpp"

#include "FiddlerCommands/FiddlerNegate.hpp"
#include "FiddlerCommands/FiddlerLeftShift.hpp"
#include "FiddlerCommands/FiddlerRightShift.hpp"
#include "FiddlerCommands/FiddlerIncrement.hpp"
#include "FiddlerCommands/FiddlerDecrement.hpp"

#include "FiddlerCommands/FiddlerWrite.hpp"
#include "FiddlerCommands/FiddlerSet.hpp"

#include "FiddlerCommands/FiddlerChangeView.hpp"

#include "FiddlerCommands/FiddlerMemory/FiddlerMemorySave.hpp"
#include "FiddlerCommands/FiddlerMemory/FiddlerMemoryLoad.hpp"

#include "InputOutputFacility.hpp"
#include "StandardStreamHandler.hpp"

#include "RegisterFiddler/RegisterFiddler.hpp"
#include "RegisterFiddler/RegisterMap.hpp"
#include "RegisterFiddler/TypedMemorySpace.hpp"

#include "CombinedView.hpp"
#include "RegisterFiddler/ViewRegistersOnly.hpp"
#include "RegisterFiddler/ViewMemoryOnly.hpp"

#include "RegisterFiddler/Commands/MathCommands.hpp"
#include "RegisterFiddler/Commands/LogicCommands.hpp"
#include "RegisterFiddler/Commands/MiscCommands.hpp"
#include "RegisterFiddler/Commands/MemoryCommands.hpp"


int main(int argc, char* argv[]){
    
    auto fidRegisters = std::make_shared< register_fiddler::RegisterMap >(
        std::vector< std::string >(
            {
                "ra",
                "rb",
                "rc",
                "re"
            }
        )
    );
    
    auto regFidMemory = std::make_shared<register_fiddler::TypedMemorySpace>(0);
    
    register_fiddler::RegFiddler regFid = std::make_shared< register_fiddler::RegisterFiddler >(fidRegisters, regFidMemory
    );
    
    auto registerView = std::make_shared<register_fiddler::ViewRegistersOnly>(regFid);
    auto memoryView = std::make_shared<register_fiddler::ViewMemoryOnly>(regFid);
    
    auto registerDisplay = std::make_shared<fw_byte_manip::CombinedView>(std::vector<fw_byte_manip::View>({ registerView, memoryView }) );

    Fiddler fiddler = std::make_shared<MockFiddler>();

    ValueParser parser = std::make_shared<StringNumberConverter>();
    
    std::map<std::string, Mfd_View> views(
        {
            {"interpret", std::make_shared<FiddlerInterpretationView>()},
            {"flags", std::make_shared<FiddlerFlagView>()}
        }
    );
    
    std::shared_ptr<FiddlerViewModes> display = std::make_shared<FiddlerViewModes>(views);
    
    std::shared_ptr<TypedMemory> mem = std::make_shared<TypedMemory>(0);


    std::map<std::string, Instruction> commandMap(
        {
            {"add", std::make_shared<register_fiddler::Addition>(regFid, registerDisplay, parser)},
            {"sub", std::make_shared<register_fiddler::Subtraction>(regFid, registerDisplay, parser)},
            {"mul", std::make_shared<register_fiddler::Multiplication>(regFid, registerDisplay, parser)},
            {"div", std::make_shared<register_fiddler::Division>(regFid, registerDisplay, parser)},
            {"and", std::make_shared<register_fiddler::And>(regFid, registerDisplay, parser)},
            {"or", std::make_shared<register_fiddler::Or>(regFid, registerDisplay, parser)},
            {"xor", std::make_shared<register_fiddler::Xor>(regFid, registerDisplay, parser)},
            {"xnor", std::make_shared<register_fiddler::Xnor>(regFid, registerDisplay, parser)},
            {"move", std::make_shared<register_fiddler::Move>(regFid, registerDisplay, parser)},
            {"neg", std::make_shared<register_fiddler::Negate>(regFid, registerDisplay, parser)},
            {"set", std::make_shared<register_fiddler::ToggleBit>(regFid, registerDisplay, parser)},
            {"shift", std::make_shared<register_fiddler::Shift>(regFid, registerDisplay, parser)},
            {"count", std::make_shared<register_fiddler::Count>(regFid, registerDisplay, parser)},
            {"save", std::make_shared<register_fiddler::Save>(regFid, registerDisplay, parser)},
            {"load", std::make_shared<register_fiddler::Load>(regFid, registerDisplay, parser)},
            {"views", std::make_shared<FiddlerChangeView>(display)}
        }
    );

    InstructionSet commands = std::make_shared<InstructionMap>(commandMap);
    
    InputOutputHandler io = std::make_shared<StandardStreamHandler>();
    
    ControlElement b(commands, io);
    
    b.loop();
    
    return 0;
}
