#include "FiddlerDivision.hpp"
#include <exception>

std::string FiddlerDivision::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    if(value == 0){
        throw std::exception();
        return view->display(target);
    }
    
    int result = target->byte / value;
    
    int rest = target->byte % value;
    
    target->rest = rest;
    target->byte = result;
    
    target->zero = (target->byte == 0);
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerDivision::usage(){
    return std::string("<unsigned operand>");
}
