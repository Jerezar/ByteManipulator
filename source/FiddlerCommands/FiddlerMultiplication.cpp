#include "FiddlerMultiplication.hpp"
#include <exception>

std::string FiddlerMultiplication::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    int result = target->byte * value;
    
    target->carry = (result < 0 || result > 255);
    
    target->byte = result;
    
    target->zero = (target->byte == 0);
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerMultiplication::usage(){
    return std::string("mul <unsigned operand>");
}
