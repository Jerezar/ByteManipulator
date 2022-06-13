#include "ByteManipulator.hpp"

#include <string>
#include "string_utils.hpp"

#include <exception>

#include "InstructionWrapper.hpp"

const std::string ByteManipulator::quit = ("quit");
const std::string ByteManipulator::help = ("help");

ByteManipulator::ByteManipulator(InstructionSet cS, InputOutputHandler _io, Instruction _pre, Instruction _post){
    commandSet = cS;
    io = _io;
    preInstruction = _pre;
    postInstruction = _post;
}

void ByteManipulator::loop(){

    io->print(preInstruction->execute(std::vector< std::string >()));

    io->print(ByteManipulator::help + "\tShow commands");
    io->print(ByteManipulator::quit + "\tEnd program");
    while (true){
        std::string input = io->read("Input: ");
        
        if(input == ByteManipulator::quit) {
            break;
        } else if(input == ByteManipulator::help){
            io->print(ByteManipulator::help + "\tShow commands");
            io->print(ByteManipulator::quit + "\tEnd program");
            io->print(commandSet->help());
        } else {
            
            std::vector< std::string > args = split( input, " ");
            if(args.size() > 0){
                Instruction command = commandSet->getInstruction(args[0]);
                std::string output;
                
                try{
                    output = command->execute(args);
                } catch (std::exception e){
                    io->print(args[0] + command->usage());
                }
                
                io->print(output);
            }
        }
    }
    
    io->print(postInstruction->execute(std::vector< std::string >()));
}
