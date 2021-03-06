#include "RunScript.hpp"

#include "ControlElement.hpp"
#include "InputOutputHandlers/ScriptReader.hpp"
#include <exception>
#include "string_utils.hpp"

namespace fw_byte_manip{
    /**
    * Takes one argument, the path to the file that should be run as a script. If one of the lines read from the file is ControlElement::quit it stops executing.
    *@throws std::exception If no argument is given.
    */
    std::string RunScript::execute(std::vector<std::string> args){
        if(args.size() == 1){
            throw std::exception();
        }
        ScriptReader io(args.at(1));
        
        std::string input = io.read("");
        std::string output("{\n");
        
        while(input != ControlElement::quit){
            std::vector< std::string > args = fw_byte_manip::string_utils::split( input, " ");
            if(args.size() > 0){
                Instruction command = commandSet->getInstruction(args[0]);
                output += command->execute(args) + "\n";
            }
            input = io.read("");
        }
        output+="}\n";
        return output;
    }
    
    std::string RunScript::usage(){
        return "<path>";
    }
}
