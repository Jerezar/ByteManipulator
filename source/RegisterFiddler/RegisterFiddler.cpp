#include "RegisterFiddler.hpp"

namespace register_fiddler{
    const uint8_t RegisterFiddler::carryFlag = 1;
    const uint8_t RegisterFiddler::zeroFlag = 1 << 1;
    const uint8_t RegisterFiddler::parityFlag = 1 << 2;
    
    uint8_t RegisterFiddler::get(std::string source){
        return registers->get(source);
    }
    
    void RegisterFiddler::add(std::string target, uint8_t value){
        int result = registers->get(target) + value;
        
        registers->set(target, result);
        
        setFlags( carryFlag, (result > 255 || result < 0) );
        setFlags( zeroFlag, (result == 0) );
        setFlags( parityFlag, this->parity(target) );
        remainder = 0;
    }
    void RegisterFiddler::add(std::string target, std::string source){
        this->add(target, registers->get(source));
    }
    
    
    void RegisterFiddler::sub(std::string target, uint8_t value){
        int result = registers->get(target) - value;
        
        registers->set(target, result);
        
        setFlags( carryFlag, (result > 255 || result < 0) );
        setFlags( zeroFlag, (result == 0) );
        setFlags( parityFlag, this->parity(target) );
        remainder = 0;
    }
    void RegisterFiddler::sub(std::string target, std::string source){
        this->sub(target, registers->get(source));
    }
    
    
    void RegisterFiddler::mul(std::string target, uint8_t value){
        int result = registers->get(target) * value;
        
        registers->set(target, result);
        
        setFlags( carryFlag, (result > 255 || result < 0) );
        setFlags( zeroFlag, (result == 0) );
        setFlags( parityFlag, this->parity(target) );
        remainder = result - registers->get(target);
    }
    void RegisterFiddler::mul(std::string target, std::string source){
        this->sub(target, registers->get(source));
    }
    
    
    bool RegisterFiddler::parity(std::string target){
        bool result = true;
        uint8_t value = get(target);
        
        for(int i = 0; i < 8; i++){
            if(value & (1 << i)){
                result = !result;
            }
        }
        
        return result;
    }
    
    void RegisterFiddler::setFlags(uint8_t mask, bool value){
        
        if(value){
            flags |= mask;
        } else {
            flags &= ~mask;
        }
    }
}
