#include "TypedMemorySpace.hpp"
#include <exception>

namespace register_fiddler{
    TypedMemorySpace::TypedMemorySpace(uint8_t defaultValue): mem(defaultValue){
    }
    
    void TypedMemorySpace::set(unsigned int index, uint8_t value){
        if(index >= TypedMemory::RAWMEMORYSIZE){
            throw std::out_of_range("Index only valid between 0 and " + std::to_string(TypedMemory::RAWMEMORYSIZE) + "\n");
        }
        mem.putChar(index, value);
        
    }
    
    uint8_t TypedMemorySpace::get(unsigned int index){
        if(index >= TypedMemory::RAWMEMORYSIZE){
            throw std::out_of_range("Index only valid between 0 and " + std::to_string(TypedMemory::RAWMEMORYSIZE) + "\n");
        }
        return mem.getChar(index);
    }
}
