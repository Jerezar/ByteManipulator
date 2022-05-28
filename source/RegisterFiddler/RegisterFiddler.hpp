#ifndef REGISTERFIDDLER_HPP
#define REGISTERFIDDLER_HPP

#include <memory>

#include <string>

namespace register_fiddler{
    class RegisterFiddler {
        
        public:
            RegisterFiddler(){};
            uint8_t get(std::string source);
            void add(std::string target, uint8_t value);
            void add(std::string target, std::string source);
            
    };
    
    using RegFiddler = std::shared_ptr<RegisterFiddler>;
}

#endif
