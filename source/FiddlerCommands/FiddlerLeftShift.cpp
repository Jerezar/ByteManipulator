#include "FiddlerLeftShift.hpp"

std::string FiddlerLeftShift::execute(std::vector<std::string> args){
    (void) args;
    target->carry = (target->byte & (1 << 7));

    target->byte = target->byte << 1;
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    return view->display(target);
}

std::string FiddlerLeftShift::usage(){
    return std::string("None");
}
