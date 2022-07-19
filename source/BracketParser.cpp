#include "BracketParser.hpp"

namespace fw_byte_manip{
    const std::map<char, char> BracketParser::brackets( {{'{','}'}, {'[',']'}, {'(',')'}});

    std::vector< std::string > BracketParser::parse( std::string input ){
        std::vector< std::string > result;
        
        size_t pos = 0;
        
        while(pos < input.size()){
            char c = input.at(pos);
            
            if(std::isspace(c)){
                pos++;
            } else if (c == '"'){
                size_t quote_start = pos;
                
                pos = input.find("\"", quote_start+1);
                
                if(pos == std::string::npos){
                    pos = input.size();
                }
                
                result.push_back(input.substr(quote_start+1, pos-quote_start - 1));
                pos++;
            } else {
                std::map<char, char>::const_iterator bracketPair = BracketParser::brackets.find(c);
                if( bracketPair != BracketParser::brackets.end()){
                    int openBrackets = 1;
                    size_t bracketStart = pos;
                    
                    while(pos < input.size()){
                        pos++;
                        if(input.at(pos) == bracketPair->first){
                            openBrackets++;
                        } else if(input.at(pos) == bracketPair->second){
                            openBrackets--;
                            if(openBrackets == 0){
                                break;
                            }
                        }
                    }
                    
                    result.push_back(input.substr(bracketStart + 1, pos-bracketStart-1));
                    pos++;
                    
                } else {
                
                    size_t word_begin = pos;
                    
                    while( pos < input.size() && !std::isspace(input.at(pos)) ){
                        pos++;
                    }
                    
                    result.push_back(input.substr(word_begin, pos-word_begin));
                }
            }
        }
        
        return result;
    }
}
