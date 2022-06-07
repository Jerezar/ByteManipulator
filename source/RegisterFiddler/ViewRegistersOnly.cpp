#include "ViewRegistersOnly.hpp"
#include <bitset>
#include <sstream>
#include <iomanip>
#include <vector>

namespace register_fiddler{
    std::string ViewRegistersOnly::display(){
        std::ostringstream result;
        
        result << std::setw(8) << "" << "  ";
        result << std::setw(8) << "PZC" << std::endl;
        
        result << std::setw(8) << "Flags" << ": ";
        result << std::setw(8) << std::bitset<8>(fiddler->getFlags()).to_string() << std::endl << std::endl;
        
        std::vector<std::string> names = fiddler->getRegisters()->getNames();
        
        for(std::vector<std::string>::iterator iter = names.begin(); iter < names.end(); iter++){
            result << std::setw(8) << *iter << ": ";
            result << std::setw(8) << std::bitset<8>(fiddler->get(*iter)).to_string() << std::endl;
        }
        
        return result.str();
    }
}
