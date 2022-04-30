#include "FiddlerDecrement.hpp"

std::string FiddlerDecrement::execute(std::vector<std::string> args){
    (void) args;
    --(target->byte);
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    return view->display(target);
}

std::string FiddlerDecrement::usage(){
    return std::string("None");
}
