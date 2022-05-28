#ifndef STRINGNUMBERCONVERTER_HPP
#define STRINGNUMBERCONVERTER_HPP

#include <stdint.h>
#include <string>

#include <exception>

#include "NumberStringParser.hpp"

class StringNumberConverter: public NumberStringParser{


    public:
    
        struct InvalidInputException: public std::exception{
        
        };
        
        virtual int getValueFromString(std::string string_rep) override;
        static uint8_t getBinaryFromString(std::string string_rep);
        static uint8_t getOctalFromString(std::string string_rep);
        static uint8_t getHexFromString(std::string string_rep);
        static uint8_t getDecimalFromString(std::string string_rep);
        
        virtual bool canParse(std::string string_rep) override;
        bool isBinary(std::string string_rep);
        bool isOctal(std::string string_rep);
        bool isDecimal(std::string string_rep);
        bool isHex(std::string string_rep);
};

#endif
