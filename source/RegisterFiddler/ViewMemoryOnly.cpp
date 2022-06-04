#include "ViewMemoryOnly.hpp"
#include <bitset>
#include <sstream>
#include <iomanip>

namespace register_fiddler{
    std::string ViewMemoryOnly::display(){
        std::ostringstream result;
        
        MemBlock mem = fiddler->getMem();
        
        result << std::hex;
        for(int i = 0; i < mem->getSize(); i = i + 16){
            result << std::setw(8) << i << ": ";
            char fillC = result.fill();
           for( int j = 0; i + j < mem->getSize() && j < 16; j++){
              result << std::setfill('0');
              result << std::setw(2) << int(mem->get(i + j)) << " ";
           }
           result << std::endl;
           result << std::setfill(fillC);
        }
        
        return result.str();
    }
}
