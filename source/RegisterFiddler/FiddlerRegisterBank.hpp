#ifndef FIDDLERREGISTERBANK_HPP
#define FIDDLERREGISTERBANK_HPP

#include <memory>
#include <string>
#include <vector>

namespace register_fiddler{
    /**
    * An object that has a number of named bytes (registers) and can modify them.
    */
    class FiddlerRegisterBank{
        public:
            virtual uint8_t get(std::string source) = 0;
            virtual void set(std::string target, uint8_t value) = 0;
            /**
            *@returns The names of all registers
            */
            virtual std::vector<std::string> getNames() = 0;
            /**
            *Inverts all the bits of the target register
            */
            virtual void negate(std::string target) =0;
            /**
            *Toggles the specified bit of the target register.
            */
            virtual void toggleBit(std::string target, unsigned int index) = 0;
    };
    
    using RegisterBank = std::shared_ptr<FiddlerRegisterBank>;
}
#endif
