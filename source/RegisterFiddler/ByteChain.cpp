#include "ByteChain.hpp"

namespace register_fiddler{
    ByteChain::ByteChain(std::vector<uint8_t> _bytes){
        bytes = _bytes;
    }
    
    ByteChain::ByteChain(void* src, int size){
        bytes = std::vector<uint8_t>(size, 0);
        for (int i=0; i<size; i++){
            bytes[i] = reinterpret_cast<uint8_t*>(src)[i];
        }
    }
    
    void ByteChain::dump(void* dest, int size){
        for (int i=0; i<size; i++){
            reinterpret_cast<uint8_t*>(dest)[i] = bytes[i];
        }
    }
    
    const uint8_t& ByteChain::operator[](unsigned int index) const { 
        return bytes[index];
    }
    
    std::vector<uint8_t> ByteChain::getBytes() const{
        return bytes;
    }
    
    unsigned int ByteChain::size() const{
        return bytes.size();
    }
}
