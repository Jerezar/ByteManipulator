#include "FiddlerMemorySave.hpp"
#include <exception>

std::string FiddlerMemorySave::execute(std::vector<std::string> args){

    if(args.size() == 1){
        throw std::exception();
        return mem->hexDump();
    }
    int index = parser->getUnsignedInt(args.at(1));
    
    mem->putChar(index, target->byte);
    
    return mem->hexDump();
}

std::string FiddlerMemorySave::usage(){
    return std::string("<position>");
}
