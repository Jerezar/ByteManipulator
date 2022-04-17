#include "NoOperation.hpp"

NoOperation::NoOperation(){

}

std::string NoOperation::execute(std::vector<std::string> args){
    return "NOP\n";
}

std::string NoOperation::usage(){
    return std::string("None");
}
