#include "ByteManipulator.hpp"

#include <memory>

#include <map>
#include <string>

#include "InstructionRegistry.hpp"
#include "InstructionMap.hpp"

#include "InstructionWrapper.hpp"
#include "NoOperation.hpp"

int main(int argc, char* argv[]){

    Instruction test = std::make_shared<NoOperation>();

    std::map<std::string, Instruction> commandMap(
        {
            {"test", test}
        }
    );

    InstructionSet commands = std::make_shared<InstructionMap>(commandMap);
    
    ByteManipulator b(commands);
    
    b.loop();
    
    return 0;
}
