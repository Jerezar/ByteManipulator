#ifndef STRINGNUMBERCONVERTER_HPP
#define STRINGNUMBERCONVERTER_HPP

#include <stdint.h>
#include <string>

#include <exception>

class StringNumberConverter{


    public:
    
        struct InvalidInputException: public std::exception{
        
        };
        
        static uint8_t getValueFromString(std::string string_rep);
        static uint8_t getBinaryFromString(std::string string_rep);
        static uint8_t getOctalFromString(std::string string_rep);
        static uint8_t getHexFromString(std::string string_rep);
        static uint8_t getDecimalFromString(std::string string_rep);
};

#endif
