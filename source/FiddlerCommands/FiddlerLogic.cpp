#include "FiddlerLogic.hpp"

std::string FiddlerAnd::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    int result = value & target->byte;
    
    target->carry = false;
    
    target->byte = result;
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerAnd::usage(){
    return std::string("<unsigned operand>");
}



std::string FiddlerOr::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    int result = value | target->byte;
    
    target->carry = false;
    
    target->byte = result;
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerOr::usage(){
    return std::string("<unsigned operand>");
}



std::string FiddlerXor::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    int result = value ^ target->byte;
    
    target->carry = false;
    
    target->byte = result;
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerXor::usage(){
    return std::string("<unsigned operand>");
}



std::string FiddlerXnor::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getValueFromString(args.at(1));
    
    int result = value ^ target->byte;
    
    target->carry = false;
    
    target->byte = ~result;
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerXnor::usage(){
    return std::string("<unsigned operand>");
}
