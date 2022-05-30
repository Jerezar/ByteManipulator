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

#include "RegisterFiddler/ViewRegistersOnly.hpp"

#include "RegisterFiddler/Commands/MathCommands.hpp"

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
    
    register_fiddler::RegFiddler regFid = std::make_shared< register_fiddler::RegisterFiddler >(fidRegisters
    );
    
    auto registerView = std::make_shared<register_fiddler::ViewRegistersOnly>(regFid);

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
            {"add", std::make_shared<register_fiddler::Addition>(regFid, registerView, parser)},
            {"sub", std::make_shared<register_fiddler::Subtraction>(regFid, registerView, parser)},
            {"mul", std::make_shared<register_fiddler::Multiplication>(regFid, registerView, parser)},
            {"div", std::make_shared<register_fiddler::Division>(regFid, registerView, parser)},
            {"and", std::make_shared<FiddlerAnd>(fiddler, parser, display)},
            {"or", std::make_shared<FiddlerOr>(fiddler, parser, display)},
            {"xor", std::make_shared<FiddlerXor>(fiddler, parser, display)},
            {"xnor", std::make_shared<FiddlerXnor>(fiddler, parser, display)},
            {"write", std::make_shared<FiddlerWrite>(fiddler, parser, display)},
            {"set", std::make_shared<FiddlerSet>(fiddler, parser, display)},
            {"lshift", std::make_shared<FiddlerLeftShift>(fiddler, display)},
            {"rshift", std::make_shared<FiddlerRightShift>(fiddler, display)},
            {"neg", std::make_shared<FiddlerNegate>(fiddler, display)},
            {"inc", std::make_shared<FiddlerIncrement>(fiddler, display)},
            {"dec", std::make_shared<FiddlerDecrement>(fiddler, display)},
            {"save", std::make_shared<FiddlerMemorySave>(fiddler, display, parser, mem)},
            {"load", std::make_shared<FiddlerMemoryLoad>(fiddler, display, parser, mem)},
            {"views", std::make_shared<FiddlerChangeView>(display)}
        }
    );

    InstructionSet commands = std::make_shared<InstructionMap>(commandMap);
    
    InputOutputHandler io = std::make_shared<StandardStreamHandler>();
    
    ControlElement b(commands, io);
    
    b.loop();
    
    return 0;
}
