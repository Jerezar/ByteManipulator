#include "FiddlerWrite.hpp"
#include <exception>

std::string FiddlerWrite::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    target->carry = false;
    
    target->byte = value;
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerWrite::usage(){
    return std::string("<unsigned operand>");
}
