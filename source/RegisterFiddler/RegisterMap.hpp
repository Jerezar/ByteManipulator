#ifndef FIDDLER_REGISTERMAP_HPP
#define FIDDLER_REGISTERMAP_HPP

#include "FiddlerRegisterBank.hpp"
#include <vector>
#include <map>

namespace register_fiddler{
    class RegisterMap: public FiddlerRegisterBank{
        private:
            std::map< std::string, uint8_t > values;
        public:
            RegisterMap( std::vector< std::string > names , uint8_t value = 0);
            virtual uint8_t get(std::string source) override;
            virtual void set(std::string target, uint8_t value) override;
    };
}

#endif
