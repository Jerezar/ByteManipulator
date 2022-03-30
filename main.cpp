#include "ByteManipulator.hpp"

#include <memory>

#include <map>
#include <string>

#include "InstructionRegistry.hpp"
#include "InstructionMap.hpp"

#include "InstructionWrapper.hpp"
#include "NoOperation.hpp"

#include "InputOutputFacility.hpp"
#include "StandardStreamHandler.hpp"

int main(int argc, char* argv[]){

    Instruction test = std::make_shared<NoOperation>();

    std::map<std::string, Instruction> commandMap(
        {
            {"test", test}
        }
    );

    InstructionSet commands = std::make_shared<InstructionMap>(commandMap);
    
    InputOutputHandler io = std::make_shared<StandardStreamHandler>();
    
    ByteManipulator b(commands, io);
    
    b.loop();
    
    return 0;
}
