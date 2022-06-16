#include "ControlElement.hpp"

#include <string>
#include "string_utils.hpp"

#include <exception>

#include "InstructionWrapper.hpp"

const std::string ControlElement::quit = ("quit");
const std::string ControlElement::help = ("help");

ControlElement::ControlElement(InstructionSet cS, InputOutputHandler _io, Instruction _pre, Instruction _post){
    commandSet = cS;
    io = _io;
    preInstruction = _pre;
    postInstruction = _post;
}

void ControlElement::loop(){
    io->print(preInstruction->execute(std::vector< std::string >()));

    io->print(ControlElement::help + "\tShow commands");
    io->print(ControlElement::quit + "\tEnd program");
    while (true){
        std::string input = io->read("Input: ");
        
        if(input == ControlElement::quit) {
            break;
        } else if(input == ControlElement::help){
            io->print(ControlElement::help + "\tShow commands");
            io->print(ControlElement::quit + "\tEnd program");
            io->print(commandSet->help());
        } else {
            
            std::vector< std::string > args = fw_byte_manip::string_utils::split( input, " ");
            if(args.size() > 0){
                Instruction command = commandSet->getInstruction(args[0]);
                std::string output;
                
                try{
                    output = command->execute(args);
                } catch (std::exception const& e){
                    io->print(args[0] + " " + command->usage() + "\n" + e.what());
                }
                
                io->print(output);
            }
        }
    }
    
    io->print(postInstruction->execute(std::vector< std::string >()));
}
