#include "TypedMemorySpace.hpp"
#include <exception>



namespace register_fiddler{
    TypedMemorySpace::TypedMemorySpace(uint8_t defaultValue): mem(defaultValue){
    }
    
    /**
    * @throws std::out_of_range if trying to access an index larger than the size.
    */
    void TypedMemorySpace::set(unsigned int index, uint8_t value){
        if(index >= TypedMemory::RAWMEMORYSIZE){
            throw std::out_of_range("Index only valid between 0 and " + std::to_string(TypedMemory::RAWMEMORYSIZE) + "\n");
        }
        mem.putChar(index, value);
        
    }
    
    /**
    * @throws std::out_of_range if trying to access an index larger than the size.
    */
    uint8_t TypedMemorySpace::get(unsigned int index){
        if(index >= TypedMemory::RAWMEMORYSIZE){
            throw std::out_of_range("Index only valid between 0 and " + std::to_string(TypedMemory::RAWMEMORYSIZE) + "\n");
        }
        return mem.getChar(index);
    }
    
    void TypedMemorySpace::write(ByteChain pat, unsigned int index, unsigned int maxLen){
        if (maxLen == 0){
            maxLen = this->getSize();
        }
        for(unsigned int i = 0; (i < pat.size()) && (i < maxLen) && (index + i < getSize()); i++){
            this->set(index + i, pat[i]);
        }        
    }
    
    ByteChain TypedMemorySpace::read(unsigned int index, unsigned int len){
        std::vector<uint8_t> bytes;
        
        for(unsigned int i = 0; (i < len) && (index + i < this->getSize()); i++){
            bytes.push_back( this->get(index + i) );
        }
        
        return ByteChain(bytes);
    }
    
    unsigned int TypedMemorySpace::getSize(){
       return TypedMemory::RAWMEMORYSIZE;
    }
}
