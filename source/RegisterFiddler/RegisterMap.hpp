#ifndef FIDDLER_REGISTERMAP_HPP
#define FIDDLER_REGISTERMAP_HPP

#include "FiddlerRegisterBank.hpp"
#include <vector>
#include <map>

namespace register_fiddler{
    /**
    * Keeps byts in a map.
    *
    * Number of registers is based on the amount of names it was constructed with.
    */
    class RegisterMap: public FiddlerRegisterBank{
        private:
            std::map< std::string, uint8_t > values;
        public:
            /**
            *@param names The list of names to be given to the registers.
            *@param value The initial value of all the registers.
            */
            RegisterMap( std::vector< std::string > names , uint8_t value = 0);
            virtual uint8_t get(std::string source) override;
            virtual void set(std::string target, uint8_t value) override;
            virtual std::vector<std::string> getNames() override;
            virtual void negate(std::string target) override;
            virtual void toggleBit(std::string target, unsigned int index) override;
    };
}

#endif
