#include "string_utils.hpp"

namespace fw_byte_manip{
    namespace string_utils{
    
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
        
        int codepoint_to_utf8( uint32_t c ){
            int result = 0;
            
            if (c < 128){
                result |=  (c & 0xFF);
            } else if( c < 0x0800 ){
                result |= ( ( ( (c >> (0*6)) & 0b00111111) | 0b10000000) << (0*8) );
                result |= ( ( ( (c >> (1*6)) & 0b00011111) | 0b11000000) << (1*8) );
            } else if( c < 0x10000){
                result |= ( ( ( (c >> (0*6)) & 0b00111111) | 0b10000000) << (0*8) );
                result |= ( ( ( (c >> (1*6)) & 0b00111111) | 0b10000000) << (1*8) );
                result |= ( ( ( (c >> (2*6)) & 0b00001111) | 0b11100000) << (2*8) );
            } else {
                result |= ( ( ( (c >> (0*6)) & 0b00111111) | 0b10000000) << (0*8) );
                result |= ( ( ( (c >> (1*6)) & 0b00111111) | 0b10000000) << (1*8) );
                result |= ( ( ( (c >> (2*6)) & 0b00111111) | 0b10000000) << (2*8) );
                result |= ( ( ( (c >> (3*6)) & 0b00001111) | 0b11100000) << (3*8) );
            }
            
            return result;
        }
        
        std::string utf8_string_from_int32(int c){
            std::string result;
            
            if(c & 0xFF000000){
                result.push_back((char) (c >> (3* 8) ));
                result.push_back((char) (c >> (2* 8) ));
                result.push_back((char) (c >> (1* 8) ));
                result.push_back((char) (c >> (0* 8) ));
            } else if(c & 0xFF0000){
                result.push_back((char) (c >> (2* 8) ));
                result.push_back((char) (c >> (1* 8) ));
                result.push_back((char) (c >> (0* 8) ));
            } else if(c & 0xFF00){
                result.push_back((char) (c >> (1* 8) ));
                result.push_back((char) (c >> (0* 8) ));
            } else {
                result.push_back((char) (c >> (0* 8) ));
            }
            
            return result;
        }
        
        std::string ansi_8b_col_text(std::string text, uint8_t value){
            return "\u001b[38;5;" + std::to_string(value) + "m" + text + "\u001b[0m"; 
        }
        
        std::string ansi_8b_col_bg(std::string text, uint8_t value){
            return "\u001b[48;5;" + std::to_string(value) + "m" + text + "\u001b[0m"; 
        }
    }
}
