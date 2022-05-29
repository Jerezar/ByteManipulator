#include "ViewRegistersOnly.hpp"
#include <bitset>
#include <vector>

namespace register_fiddler{
    std::string ViewRegistersOnly::display(){
        std::string result;
        
        std::vector<std::string> names = fiddler->getRegisters()->getNames();
        
        for(std::vector<std::string>::iterator iter = names.begin(); iter < names.end(); iter++){
            result += *iter + " " + std::bitset<8>(fiddler->get(*iter)).to_string() + "\n";
        }
        
        return result;
    }
}
