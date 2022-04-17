#include "ByteManipulator.hpp"

#include <memory>

#include <map>
#include <string>

#include "InstructionRegistry.hpp"
#include "InstructionMap.hpp"

#include "MockFiddler.hpp"

#include "MockFiddlerView.hpp"
#include "FiddlerFullView.hpp"

#include "InstructionWrapper.hpp"

#include "NumberStringParser.hpp"
#include "StringNumberConverter.hpp"
#include "FiddlerCommands/FiddlerAddition.hpp"
#include "FiddlerCommands/FiddlerSubtraction.hpp"

#include "InputOutputFacility.hpp"
#include "StandardStreamHandler.hpp"

int main(int argc, char* argv[]){

    Fiddler fiddler = std::make_shared<MockFiddler>();

    ValueParser parser = std::make_shared<StringNumberConverter>();
    
    Mfd_View display = std::make_shared<FiddlerFullView>();


    std::map<std::string, Instruction> commandMap(
        {
            {"add", std::make_shared<FiddlerAddition>(fiddler, parser, display)},
            {"sub", std::make_shared<FiddlerSubtraction>(fiddler, parser, display)}
        }
    );

    InstructionSet commands = std::make_shared<InstructionMap>(commandMap);
    
    InputOutputHandler io = std::make_shared<StandardStreamHandler>();
    
    ByteManipulator b(commands, io);
    
    b.loop();
    
    return 0;
}
