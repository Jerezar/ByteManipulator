#include "FiddlerMemoryLoad.hpp"
#include <exception>

std::string FiddlerMemoryLoad::execute(std::vector<std::string> args){

    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int index = parser->getValueFromString(args.at(1));
    
    target->byte = mem->getChar(index);
    target->zero = (target->byte == 0);
    target->updateParity();
    return view->display(target);
}

std::string FiddlerMemoryLoad::usage(){
    return std::string("<position>");
}
