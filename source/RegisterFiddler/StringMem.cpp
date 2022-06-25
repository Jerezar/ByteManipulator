#include "StringMem.hpp"
#include <exception>
#include <iterator>


namespace register_fiddler{
    StringMem::StringMem(std::string init): mem(init){
    }
    
    /**
    * @throws std::out_of_range if trying to access an index larger than the size.
    */
    void StringMem::set(unsigned int index, uint8_t value){
        if(index >= this->getSize()){
            throw std::out_of_range("Index only valid between 0 and " + std::to_string(this->getSize()) + "\n");
        }
        mem[index] = value;
    }
    
    /**
    * @throws std::out_of_range if trying to access an index larger than the size.
    */
    uint8_t StringMem::get(unsigned int index){
        if(index >= this->getSize()){
            throw std::out_of_range("Index only valid between 0 and " + std::to_string(this->getSize()) + "\n");
        }
        return mem[index];
    }
    
    /**
    * Writes multiple Bytes into memory. Will automatically extend the size of memory to accomodate both index and size.
    */
    void StringMem::write(ByteChain pat, unsigned int index, unsigned int maxLen){
        if(index >= mem.size()){
            mem.append(index - mem.size(), 0);
        }
        
        std::vector<uint8_t> bytes = pat.getBytes();
        
        std::vector<uint8_t>::iterator iter = bytes.begin();
        std::vector<uint8_t>::iterator end = (maxLen > 0 && maxLen <= bytes.size()) ? (bytes.begin()+maxLen) : bytes.end();
        
        for(unsigned int i = 0; (iter < end) && (i + index < mem.size()); i++){
            this->set(i + index, *iter);
            iter++;
        }
        
        mem.append(iter, end);
    }
    
    ByteChain StringMem::read(unsigned int index, unsigned int len){
        std::vector<uint8_t> bytes;
        
        for(unsigned int i = 0; (i < len) && (index + i < this->getSize()); i++){
            bytes.push_back( this->get(index + i) );
        }
        
        return ByteChain(bytes);
    }
    
    unsigned int StringMem::getSize(){
       return mem.size();
    }
    
    void StringMem::insert(unsigned int index, unsigned int length, uint8_t val){
        mem.insert(mem.begin() + index, length, val);
    }
    void StringMem::erase(unsigned int index, unsigned int length){
        if( index < mem.length()){
            std::string::iterator start = mem.begin() + index;
            std::string::iterator end = (start + length < mem.end()) ? (start + length) : mem.end();
            mem.erase(start, end);
        }
    }
}
