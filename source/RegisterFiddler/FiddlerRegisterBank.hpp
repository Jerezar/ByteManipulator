#ifndef FIDDLERREGISTERBANK_HPP
#define FIDDLERREGISTERBANK_HPP

#include <memory>
#include <string>
#include <vector>

namespace register_fiddler{
    class FiddlerRegisterBank{
        public:
            virtual uint8_t get(std::string source) = 0;
            virtual void set(std::string target, uint8_t value) = 0;
            virtual std::vector<std::string> getNames() = 0;
            virtual void negate(std::string target) { set( target, ~(get(target)) );};
            virtual void toggleBit(std::string target, unsigned int index) { set( target, (get(target)) ^ (1 << index)) ;};
    };
    
    using RegisterBank = std::shared_ptr<FiddlerRegisterBank>;
}
#endif
