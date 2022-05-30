#include "StringNumberConverter.hpp"

#include <iostream>

#include <regex>

int StringNumberConverter::getValueFromString(std::string string_rep){
    
    if(this->isBinary(string_rep)){
        return StringNumberConverter::getBinaryFromString(string_rep);
    } else if(isOctal(string_rep)){
        return StringNumberConverter::getOctalFromString(string_rep);
    } else if(isHex(string_rep)){
        return StringNumberConverter::getHexFromString(string_rep);
    } else if(isDecimal(string_rep)){
        return StringNumberConverter::getDecimalFromString(string_rep);
    } else {
        throw InvalidInputException();
        return 0;
    }
}

uint8_t StringNumberConverter::getBinaryFromString(std::string string_rep){
    uint8_t result = 0;
    
    string_rep.erase(0, 2);
    
    std::string::reverse_iterator iter = string_rep.rbegin();
    for(int i = 0;
        i < 8 && iter < string_rep.rend();
        i++){
        
        if(*iter == '1'){
            result |= (1 << i);
        }
        
        ++iter;
    }
    
    return result;
}

uint8_t StringNumberConverter::getOctalFromString(std::string string_rep){
    uint8_t result = 0;
    
    string_rep.erase(0, 2);
    
    for(std::string::iterator iter = string_rep.begin();
        iter< string_rep.end();
        iter++){
        result *= 8;
        int number = *iter - '0';
        result += number;
    }
    
    return result;
}

uint8_t StringNumberConverter::getHexFromString(std::string string_rep){
    uint8_t result = 0;
    
    string_rep.erase(0, 2);
    
    for(std::string::iterator iter = string_rep.begin();
        iter< string_rep.end();
        iter++){
        result *= 16;
        int number;
        if(*iter <= '9'){
            number = *iter - '0';
        } else if(*iter >= 'A' && *iter <= 'F'){
            number = *iter - 'A' + 10;
        } else if(*iter >= 'a' && *iter <= 'f'){
            number = *iter - 'a' + 10;
        }
        result += number;
    }
    
    return result;
}

uint8_t StringNumberConverter::getDecimalFromString(std::string string_rep){
    uint8_t result = 0;
    
    for(std::string::iterator iter = string_rep.begin();
        iter< string_rep.end();
        iter++){
        result *= 10;
        int number = *iter - '0';
        result += number;
    }
    
    return result;
}

bool StringNumberConverter::canParse(std::string string_rep){
    return isBinary(string_rep) || isOctal(string_rep) || isDecimal(string_rep) || isHex(string_rep);
}

bool StringNumberConverter::isBinary(std::string string_rep){
    std::regex bin_pat("0[bB]([01]+)");
    return std::regex_match(string_rep.begin(), string_rep.end(), bin_pat);
}

bool StringNumberConverter::isOctal(std::string string_rep){
    std::regex oct_pat("0[oO]([0-7]+)");
    return std::regex_match(string_rep.begin(), string_rep.end(), oct_pat);
}

bool StringNumberConverter::isDecimal(std::string string_rep){
    std::regex dec_pat("[0-9]+");
    return std::regex_match(string_rep.begin(), string_rep.end(), dec_pat);
    
}

bool StringNumberConverter::isHex(std::string string_rep){
    std::regex hex_pat("0[xX]([0-9a-fA-F]+)");
    return std::regex_match(string_rep.begin(), string_rep.end(), hex_pat);
}
