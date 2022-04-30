#include "ControlElement.hpp"

#include <string>
#include "string_utils.hpp"

#include <exception>

#include "InstructionWrapper.hpp"

ControlElement::ControlElement(InstructionSet cS, InputOutputHandler _io){
    commandSet = cS;
    io = _io;
}

void ControlElement::loop(){
    io->print("help\tShow commands");
    io->print("quit\tEnd program");
    while (true){
        std::string input = io->read("Input: ");
        
        if(input == "quit") {
            return;
        } else if(input == "help"){
            io->print("help\tShow commands");
            io->print("quit\tEnd program");
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
}