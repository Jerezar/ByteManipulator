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

/**
* First executes the preInstruction and prints the output of that.
* Then prints the innate commands.
* Afterwards, in a loop, it reads lines of input, with the arguments separated be spaces. The first argument is the name of the command that is to be called.
*@note The innate commands take priority, but have no arguments and only execute if the entire input matches. If the InstructionSet has commands of the same name, those will only execute if they *do* take arguments.
*
* If an exception is caught in the execution of a command, the usage of that command is printed instead of its output.
* Once the loop is ended with the quit command, the postInstruction is executed. 
*/
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
            
            std::vector< std::string > args = split( input, " ");
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
