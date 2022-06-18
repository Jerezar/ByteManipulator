#include "RegisterInterpretationView.hpp"
#include <bitset>
#include <sstream>
#include <iomanip>
#include <vector>
#include "string_utils.hpp"

namespace register_fiddler{
    std::string RegisterInterpretationView::display(){
        std::ostringstream result;
        
        
        
        std::vector<std::string> names = fiddler->getRegisters()->getNames();        
        
        result << std::setw(8) << "Reg" << "  ";
        result << std::setw(8) << "Byte"<< " ";
        result << std::setw(5) << "Oct"<< " ";
        result << std::setw(5) << "Dec"<< " ";
        result << std::setw(5) << "Hex"<< " ";
        result << std::setw(6) << "ASCII"<< " ";
        result << std::setw(10) << "ISO-8859-1"<< " ";
        result << std::setw(5) << "%"<< " ";
        result << std::setw(5) << "Col" << std::endl;
        
        for(std::vector<std::string>::iterator iter = names.begin(); iter < names.end(); iter++){
            uint8_t regByte = fiddler->get(*iter);
            
            result << std::setw(8) << *iter << ": ";
            result << std::setw(8) << std::bitset<8>(regByte).to_string() << " ";
            result << std::setw(5) << std::oct << (int)regByte << " ";
            result << std::setw(5) << std::dec << (int)regByte << " ";
            result << std::setw(5) << std::hex << (int)regByte << " ";
            result << std::dec;
            
            result << std::setw(6) << char( std::isprint(regByte) ? regByte : ' ' ) << " ";
            
            int utfChar = fw_byte_manip::string_utils::codepoint_to_utf8(regByte);
            result << std::setw(10);
            if(std::isprint(utfChar)){
                result << fw_byte_manip::string_utils::utf8_string_from_int32(utfChar);
            } else {
                result << " ";
            }
            result << " ";
            
            result << std::setw(5) << std::setprecision(2) << std::fixed << (100 * (((float)regByte)/255)) << " ";
            
            result << std:: setw(5) << fw_byte_manip::string_utils::ansi_8b_col_text("TEXT", regByte);
            result << std::endl;
        }
        
        return result.str();
    }
}
