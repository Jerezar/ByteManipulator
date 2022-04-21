#include "FiddlerNegate.hpp"

std::string FiddlerNegate::execute(std::vector<std::string> args){
    

    target->byte = ~target->byte;
    
    
    
    return view->display(target);
}

std::string FiddlerNegate::usage(){
    return std::string("None");
}
