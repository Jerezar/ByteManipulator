#include "ByteManipulator.hpp"

#include <string>
#include "string_utils.hpp"

#include "InstructionWrapper.hpp"

ByteManipulator::ByteManipulator(InstructionSet cS, InputOutputHandler _io){
    commandSet = cS;
    io = _io;
}

void ByteManipulator::loop(){
    while (true){
        std::string input = io->read("Input: ");
        
        if(input == "quit") return;
        
        std::vector< std::string > args = split( input, " ");
        
        Instruction command = commandSet->getInstruction(args[0]);
        std::string output = command->execute(args);
        
        io->print(output);
    }
}
