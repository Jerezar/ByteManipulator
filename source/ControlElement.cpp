#include "ControlElement.hpp"

#include <string>

#include <exception>

#include "InstructionWrapper.hpp"

namespace fw_byte_manip{
    
    const std::string ControlElement::quit = ("quit");
    const std::string ControlElement::help = ("help");
    
    ControlElement::ControlElement(InstructionSet cS, InputOutputHandler _io, Preprocessor _preprocessor, Instruction _pre, Instruction _post){
        commandSet = cS;
        io = _io;
        preprocessor = _preprocessor;
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
        io->print(ControlElement::help + "\tShow commands");
        io->print(ControlElement::quit + "\tEnd program");
        
        io->print(preInstruction->execute(std::vector< std::string >()));
        
        
        while (true){
            std::string rawInput = io->read("Input: ");
            
            if(rawInput == ControlElement::quit) {
                break;
            } else {
                this->handle(rawInput);
            }
        }
        
        io->print(postInstruction->execute(std::vector< std::string >()));
    }
    
    
    void ControlElement::handle(std::string rawInput){
        if(rawInput == ControlElement::help){
                io->print(ControlElement::help + "\tShow commands");
                io->print(ControlElement::quit + "\tEnd program");
                io->print(commandSet->help());
            } else {
                
                std::vector< std::string > args = preprocessor->parse(rawInput);
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
}
