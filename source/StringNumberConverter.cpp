#include "StringNumberConverter.hpp"

#include <iostream>

#include <regex>

uint8_t StringNumberConverter::getValueFromString(std::string string_rep){
    
    std::regex bin_pat("0[bB]([01]+)");
    
    std::regex hex_pat("0[xX]([0-9a-fA-F]+)");
    
    std::regex oct_pat("0[oO]([0-7]+)");
    
    std::regex dec_pat("[0-9]+");
    
    if(std::regex_match(string_rep.begin(), string_rep.end(), bin_pat)){
        return StringNumberConverter::getBinaryFromString(string_rep);
    } else if(std::regex_match(string_rep.begin(), string_rep.end(), hex_pat)){
        return StringNumberConverter::getHexFromString(string_rep);
    } else if(std::regex_match(string_rep.begin(), string_rep.end(), oct_pat)){
        return StringNumberConverter::getOctalFromString(string_rep);
    } else if(std::regex_match(string_rep.begin(), string_rep.end(), dec_pat)){
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
