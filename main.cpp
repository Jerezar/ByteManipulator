#include "ByteManipulator.hpp"

#include <memory>

#include <map>
#include <string>

#include "InstructionRegistry.hpp"
#include "InstructionMap.hpp"

#include "MockFiddler.hpp"

#include "InstructionWrapper.hpp"

#include "FiddlerCommands/FiddlerAddition.hpp"

#include "InputOutputFacility.hpp"
#include "StandardStreamHandler.hpp"

int main(int argc, char* argv[]){

    Fiddler fiddler = std::make_shared<MockFiddler>();

    Instruction test = std::make_shared<FiddlerAddition>(fiddler);

    std::map<std::string, Instruction> commandMap(
        {
            {"add", test}
        }
    );

    InstructionSet commands = std::make_shared<InstructionMap>(commandMap);
    
    InputOutputHandler io = std::make_shared<StandardStreamHandler>();
    
    ByteManipulator b(commands, io);
    
    b.loop();
    
    return 0;
}
