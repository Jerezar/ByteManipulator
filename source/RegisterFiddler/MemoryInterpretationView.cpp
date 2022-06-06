#include "MemoryInterpretationView.hpp"
#include <bitset>
#include <sstream>
#include <iomanip>

namespace register_fiddler{
    std::string MemoryInterpretationView::display(){
        std::ostringstream result;
        
        MemBlock mem = fiddler->getMem();
        
        result << std::hex;
        for(int i = 0; i < mem->getSize(); i = i + 16){
            result << std::setw(8) << i << ": ";
           for( int j = 0; i + j < mem->getSize() && j < 16; j++){
              uint8_t b = mem->get(i + j);
              result << std::setw(2) << (char)(std::isprint(b) ? b : '.') << " ";
           }
           result << std::endl;
        }
        
        return result.str();
    }
}
