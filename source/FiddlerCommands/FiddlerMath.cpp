#include "FiddlerMath.hpp"

std::string FiddlerAddition::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getUnsignedInt(args.at(1));
    
    int result = value + target->byte;
    
    target->carry = (result > 255 || result < 0);
    
    target->byte = result;
    
    target->zero = (target->byte == 0);
    target->rest = 0;
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerAddition::usage(){
    return std::string("<unsigned operand>");
}



std::string FiddlerSubtraction::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getUnsignedInt(args.at(1));
    
    int result = target->byte - value;
    
    target->carry = (target->byte < value);
    
    target->byte = result;
    target->rest = 0;
    
    target->zero = (target->byte == 0);
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerSubtraction::usage(){
    return std::string("<unsigned operand>");
}



std::string FiddlerMultiplication::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getUnsignedInt(args.at(1));
    
    int result = target->byte * value;
    
    target->carry = (result < 0 || result > 255);
    
    target->byte = result;
    target->rest = result - target->byte;
    
    target->zero = (target->byte == 0);
    target->updateParity();
    
    
    return view->display(target);
}

std::string FiddlerMultiplication::usage(){
    return std::string("<unsigned operand>");
}



std::string FiddlerDivision::execute(std::vector<std::string> args) {
    if(args.size() == 1){
        throw std::exception();
        return view->display(target);
    }
    int value = parser->getUnsignedInt(args.at(1));
    
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
