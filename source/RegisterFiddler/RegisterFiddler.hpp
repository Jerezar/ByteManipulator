#ifndef REGISTERFIDDLER_HPP
#define REGISTERFIDDLER_HPP

#include <memory>

#include <string>
#include "FiddlerRegisterBank.hpp"

namespace register_fiddler{
    class RegisterFiddler {
        private:
            uint8_t flags;
            int remainder;
            RegisterBank registers;
        public:
            RegisterFiddler(RegisterBank _registers){
                registers = _registers;
            };
            
            static const uint8_t carryFlag;
            static const uint8_t zeroFlag;
            static const uint8_t parityFlag;
            
            uint8_t get(std::string source);
            
            void add(std::string target, uint8_t value);
            void add(std::string target, std::string source);
            
            bool parity(std::string target);
            void setFlags(uint8_t mask, bool value);
            
    };
    
    using RegFiddler = std::shared_ptr<RegisterFiddler>;
}

#endif
