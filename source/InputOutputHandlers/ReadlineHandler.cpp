#include "ReadlineHandler.hpp"

#include <readline/readline.h>
#include <readline/history.h>
#include <iostream>
#include <stdlib.h>

namespace fw_byte_manip{
    
    std::string ReadlineHandler::read(std::string prompt){
        
        char* input = readline(prompt.data());
        
        std::string result = input;
        
        if(*input)
            add_history(input);
        free(input);
        
        return result;
    }
    
    void ReadlineHandler::print(std::string output){
        std::cout << output << std::endl;
    }
    
}
