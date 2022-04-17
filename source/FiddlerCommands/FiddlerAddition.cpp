#include "FiddlerAddition.hpp"
#include <exception>

std::string FiddlerAddition::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    int result = value + target->byte;
    
    target->carry = (result > 255 || result < 0);
    
    target->byte = result;
    
    target->zero = (target->byte == 0);
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerAddition::usage(){
    return std::string("add <unsigned operand>");
}
