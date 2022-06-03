#ifndef REGISTERFIDDLER_HPP
#define REGISTERFIDDLER_HPP

#include <memory>

#include <string>
#include "FiddlerRegisterBank.hpp"
#include "MemorySpace.hpp"

namespace register_fiddler{
    class RegisterFiddler {
        private:
            uint8_t flags;
            int remainder;
            RegisterBank registers;
            MemBlock mem;
        public:
            RegisterFiddler(RegisterBank _registers, MemBlock _mem){
                registers = _registers;
                mem = _mem;
            };
            
            static const uint8_t carryFlag;
            static const uint8_t zeroFlag;
            static const uint8_t parityFlag;
            
            RegisterBank getRegisters(){ return registers; };
            uint8_t get(std::string source);
            
            void move(std::string target, uint8_t value);
            void move(std::string target, std::string source);
            
            void add(std::string target, uint8_t value);
            void add(std::string target, std::string source);
            
            void sub(std::string target, uint8_t value);
            void sub(std::string target, std::string source);
            
            void mul(std::string target, uint8_t value);
            void mul(std::string target, std::string source);
            
            void div(std::string target, uint8_t value);
            void div(std::string target, std::string source);
            
            void bit_and(std::string target, uint8_t value);
            void bit_and(std::string target, std::string source);
            
            void bit_or(std::string target, uint8_t value);
            void bit_or(std::string target, std::string source);
            
            void bit_xor(std::string target, uint8_t value);
            void bit_xor(std::string target, std::string source);
            
            void bit_xnor(std::string target, uint8_t value);
            void bit_xnor(std::string target, std::string source);
            
            void negate(std::string target);
            void shift(std::string target, bool left = true, unsigned int amount = 1);
            void count(std::string target, bool up = true);
            
            void load(std::string target, unsigned int index);
            void save(std::string source, unsigned int index);
            
            bool parity(std::string target);
            void setFlags(uint8_t mask, bool value);
            
    };
    
    using RegFiddler = std::shared_ptr<RegisterFiddler>;
}

#endif
