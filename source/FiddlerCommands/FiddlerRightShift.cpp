#include "FiddlerRightShift.hpp"

std::string FiddlerRightShift::execute(std::vector<std::string> args){
    
    target->carry = (target->byte & (1 << 0));

    target->byte = target->byte >> 1;
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    return view->display(target);
}

std::string FiddlerRightShift::usage(){
    return std::string("None");
}
