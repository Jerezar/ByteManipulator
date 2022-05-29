#ifndef REGISTERFIDDLERVIEW_HPP
#define REGISTERFIDDLERVIEW_HPP

#include <memory>
#include <string>
#include "RegisterFiddler/RegisterFiddler.hpp"

namespace register_fiddler{
    class RegisterFiddlerView{
        protected:
            RegFiddler fiddler;
        public:
            RegisterFiddlerView(RegFiddler _fiddler){ fiddler = _fiddler; };
            virtual std::string display() = 0;
    };
    
    using RegFiddlerView = std::shared_ptr<RegisterFiddlerView>;
}
#endif
