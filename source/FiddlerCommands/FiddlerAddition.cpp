#include "FiddlerAddition.hpp"
#include <exception>

std::string FiddlerAddition::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return std::to_string( (int) target->byte);
    }
    int value = std::stoi(args.at(1));
    
    int result = value + target->byte;
    
    target->carry = (result > 255 || result < 0);
    
    target->byte = result;
    return std::to_string( (int) target->byte);
}

std::string FiddlerAddition::usage(){
    return std::string("add <operand>");
}
