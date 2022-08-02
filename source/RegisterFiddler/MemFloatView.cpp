#include "MemFloatView.hpp"

#include <iostream>
#include <iomanip>

namespace register_fiddler{
    std::string MemFloatView::display(){
        std::ostringstream result;
        
        std::cout << "TestTest" << std::endl;
        
        MemBlock mem = fiddler->getMem();
        int stepsize = sizeof(float);
        
        for(int i = 0; i < mem->getSize(); i = i + 16){
           
           
           for( int j = 0; i + j < mem->getSize() && j < 16; j = j + stepsize){
               float val = 0;
               ByteChain bytes = mem->read(i+j, stepsize);
               bytes.dump(&val, stepsize);
               result << std::hex << std::setw(8) << i + j << ": " << std::dec;
               result << std::to_string(val) << std::endl;
           }
           result << std::endl;
        }
        
        return result.str();
    }
}
