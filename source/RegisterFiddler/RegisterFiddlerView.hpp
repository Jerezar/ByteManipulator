#ifndef REGISTERFIDDLERVIEW_HPP
#define REGISTERFIDDLERVIEW_HPP

#include <memory>
#include "GenericView.hpp"
#include "RegisterFiddler/RegisterFiddler.hpp"

namespace register_fiddler{
    class RegisterFiddlerView : public fw_byte_manip::GenericView{
        protected:
            RegFiddler fiddler;
        public:
            RegisterFiddlerView(RegFiddler _fiddler){ fiddler = _fiddler; };
    };
    
    using RegFiddlerView = std::shared_ptr<RegisterFiddlerView>;
}
#endif
