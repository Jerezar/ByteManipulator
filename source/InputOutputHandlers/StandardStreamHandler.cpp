#include "StandardStreamHandler.hpp"

#include <iostream>

namespace fw_byte_manip{
    StandardStreamHandler::StandardStreamHandler(){
    
    }
    
    std::string StandardStreamHandler::read(std::string prompt){
        std::string input;
        std::cout << prompt;
        std::getline(std::cin, input);
        
        return input;
    }
    
    void StandardStreamHandler::print(std::string output){
        std::cout << output << std::endl;
    }
}
