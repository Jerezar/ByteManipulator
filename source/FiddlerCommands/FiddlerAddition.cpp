#include "FiddlerAddition.hpp"

std::string FiddlerAddition::execute(std::vector<std::string> args){
    target->byte += 5;
    
    return std::to_string((int) target->byte);
}
