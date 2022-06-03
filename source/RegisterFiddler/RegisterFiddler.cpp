#include "RegisterFiddler.hpp"

#include <exception>

namespace register_fiddler{
    const uint8_t RegisterFiddler::carryFlag = 1;
    const uint8_t RegisterFiddler::zeroFlag = 1 << 1;
    const uint8_t RegisterFiddler::parityFlag = 1 << 2;
    
    uint8_t RegisterFiddler::get(std::string source){
        return registers->get(source);
    }
    
    void RegisterFiddler::move(std::string target, uint8_t value){
        registers->set(target, value);
    }
    void RegisterFiddler::move(std::string target, std::string source){
        this->move(target, registers->get(source));
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
        this->mul(target, registers->get(source));
    }
    
    
    void RegisterFiddler::div(std::string target, uint8_t value){
        if(value == 0){
            throw std::logic_error("Division by zero\n");
        }
        int targetValue = registers->get(target);
        int result = targetValue / value;
        
        registers->set(target, result);
        
        setFlags( zeroFlag, (result == 0) );
        setFlags( parityFlag, this->parity(target) );
        remainder = targetValue % value;
    }
    void RegisterFiddler::div(std::string target, std::string source){
        this->div(target, registers->get(source));
    }
    
    
    void RegisterFiddler::bit_and(std::string target, uint8_t value){
        int result = registers->get(target) & value;
        
        registers->set(target, result);
        
        setFlags( carryFlag, false );
        setFlags( zeroFlag, (result == 0) );
        setFlags( parityFlag, this->parity(target) );
        remainder = 0;
    }
    void RegisterFiddler::bit_and(std::string target, std::string source){
        this->bit_and(target, registers->get(source));
    }
    
    
    void RegisterFiddler::bit_or(std::string target, uint8_t value){
        int result = registers->get(target) | value;
        
        registers->set(target, result);
        
        setFlags( carryFlag, false );
        setFlags( zeroFlag, (result == 0) );
        setFlags( parityFlag, this->parity(target) );
        remainder = 0;
    }
    void RegisterFiddler::bit_or(std::string target, std::string source){
        this->bit_or(target, registers->get(source));
    }
    
    
    void RegisterFiddler::bit_xor(std::string target, uint8_t value){
        int result = registers->get(target) ^ value;
        
        registers->set(target, result);
        
        setFlags( carryFlag, false );
        setFlags( zeroFlag, (result == 0) );
        setFlags( parityFlag, this->parity(target) );
        remainder = 0;
    }
    void RegisterFiddler::bit_xor(std::string target, std::string source){
        this->bit_xor(target, registers->get(source));
    }
    
    
    void RegisterFiddler::bit_xnor(std::string target, uint8_t value){
        int result = registers->get(target) ^ value;
        
        registers->set(target, ~result);
        
        setFlags( carryFlag, false );
        setFlags( zeroFlag, (result == 0) );
        setFlags( parityFlag, this->parity(target) );
        remainder = 0;
    }
    void RegisterFiddler::bit_xnor(std::string target, std::string source){
        this->bit_xnor(target, registers->get(source));
    }
    
    
    void RegisterFiddler::negate(std::string target){
        registers->negate(target);
    }
    
    void RegisterFiddler::shift(std::string target, bool left, unsigned int amount){
        for(int i = 0; i < amount; i++){
            uint8_t value = get(target);
            
            if(left){
                setFlags( carryFlag, value & (1 << 8) );
                value = value << 1;
            } else {
                setFlags( carryFlag, value & (1 << 0) );
                value = value >> 1;
            }
            
            registers->set(target, value);
            
            setFlags( zeroFlag, (value == 0) );
            setFlags( parityFlag, this->parity(target) );
        }
    }
    
    void RegisterFiddler::count(std::string target, bool up){
        if(up){
            add(target, 1);
        } else {
            sub(target, 1);
        }
    }
    
    
    void RegisterFiddler::load(std::string target, unsigned int index){
        registers->set(target, mem->get(index));
    }
    
    void RegisterFiddler::save(std::string source, unsigned int index){
        mem->set(index, registers->get(source));
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
