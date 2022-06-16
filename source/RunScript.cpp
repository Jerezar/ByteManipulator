#include "RunScript.hpp"

#include "ControlElement.hpp"
#include "ScriptReader.hpp"
#include <exception>
#include "string_utils.hpp"

std::string RunScript::execute(std::vector<std::string> args){
    if(args.size() == 1){
        throw std::exception();
    }
    ScriptReader io(args.at(1));
    
    std::string input = io.read("");
    std::string output("{\n");
    
    while(input != ControlElement::quit){
        std::vector< std::string > args = split( input, " ");
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
