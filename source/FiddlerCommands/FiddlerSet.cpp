#include "FiddlerSet.hpp"
#include <exception>

std::string FiddlerSet::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    target->carry = false;
    
    target->byte = (target->byte ^ (1 << value));
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerSet::usage(){
    return std::string("set <index>");
}
