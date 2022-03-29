#include "string_utils.hpp"

std::vector< std::string > split(std::string input, std::string delim){
    std::vector<std::string> result;
    
    while( !input.empty() ){
        size_t pos = input.find(delim);
        
        result.push_back(input.substr(0, pos));
        
        input.erase(0, pos);        //getrennt, falls pos string::npos ist
        input.erase(0, delim.length());
    }
    
    return result;
}
