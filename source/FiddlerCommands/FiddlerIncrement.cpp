#include "FiddlerIncrement.hpp"

std::string FiddlerIncrement::execute(std::vector<std::string> args){

    ++(target->byte);
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    return view->display(target);
}

std::string FiddlerIncrement::usage(){
    return std::string("None");
}
