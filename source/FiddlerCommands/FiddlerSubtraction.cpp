#include "FiddlerSubtraction.hpp"
#include <exception>

std::string FiddlerSubtraction::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    int result = target->byte - value;
    
    target->carry = (target->byte < value);
    
    target->byte = result;
    
    target->zero = (target->byte == 0);
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerSubtraction::usage(){
    return std::string("sub <unsigned operand>");
}
