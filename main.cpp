#include "ByteManipulator.hpp"

#include <memory>

#include <map>
#include <string>

#include "InstructionRegistry.hpp"
#include "InstructionMap.hpp"

#include "MockFiddler.hpp"

#include "MockFiddlerView.hpp"
#include "FiddlerFlagView.hpp"
#include "FiddlerInterpretationView.hpp"

#include "InstructionWrapper.hpp"

#include "NumberStringParser.hpp"
#include "StringNumberConverter.hpp"
#include "FiddlerCommands/FiddlerAddition.hpp"
#include "FiddlerCommands/FiddlerSubtraction.hpp"
#include "FiddlerCommands/FiddlerMultiplication.hpp"
#include "FiddlerCommands/FiddlerDivision.hpp"

#include "FiddlerCommands/FiddlerAnd.hpp"
#include "FiddlerCommands/FiddlerOr.hpp"
#include "FiddlerCommands/FiddlerXor.hpp"
#include "FiddlerCommands/FiddlerXnor.hpp"

#include "FiddlerCommands/FiddlerNegate.hpp"
#include "FiddlerCommands/FiddlerLeftShift.hpp"
#include "FiddlerCommands/FiddlerRightShift.hpp"
#include "FiddlerCommands/FiddlerIncrement.hpp"
#include "FiddlerCommands/FiddlerDecrement.hpp"

#include "FiddlerCommands/FiddlerWrite.hpp"
#include "FiddlerCommands/FiddlerSet.hpp"

#include "FiddlerCommands/FiddlerMemory/FiddlerMemorySave.hpp"
#include "FiddlerCommands/FiddlerMemory/FiddlerMemoryLoad.hpp"

#include "InputOutputFacility.hpp"
#include "StandardStreamHandler.hpp"

int main(int argc, char* argv[]){

    Fiddler fiddler = std::make_shared<MockFiddler>();

    ValueParser parser = std::make_shared<StringNumberConverter>();
    
    Mfd_View display = std::make_shared<FiddlerInterpretationView>();
    
    std::shared_ptr<TypedMemory> mem = std::make_shared<TypedMemory>(0);


    std::map<std::string, Instruction> commandMap(
        {
            {"add", std::make_shared<FiddlerAddition>(fiddler, parser, display)},
            {"sub", std::make_shared<FiddlerSubtraction>(fiddler, parser, display)},
            {"mul", std::make_shared<FiddlerMultiplication>(fiddler, parser, display)},
            {"div", std::make_shared<FiddlerDivision>(fiddler, parser, display)},
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
            {"load", std::make_shared<FiddlerMemoryLoad>(fiddler, display, parser, mem)}
        }
    );

    InstructionSet commands = std::make_shared<InstructionMap>(commandMap);
    
    InputOutputHandler io = std::make_shared<StandardStreamHandler>();
    
    ByteManipulator b(commands, io);
    
    b.loop();
    
    return 0;
}
