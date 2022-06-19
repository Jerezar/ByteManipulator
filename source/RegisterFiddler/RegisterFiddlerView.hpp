#ifndef REGISTERFIDDLERVIEW_HPP
#define REGISTERFIDDLERVIEW_HPP

#include <memory>
#include "GenericView.hpp"
#include "RegisterFiddler/RegisterFiddler.hpp"

namespace register_fiddler{
    /**
    * A View specifically for displaying the contents of a RegisterFiddler object.
    */
    class RegisterFiddlerView : public fw_byte_manip::GenericView{
        protected:
            /**
            * The RegisterFiddler that is meant to be shown.
            */
            RegFiddler fiddler;
        public:
            RegisterFiddlerView(RegFiddler _fiddler){ fiddler = _fiddler; };
    };
    
    using RegFiddlerView = std::shared_ptr<RegisterFiddlerView>;
}
#endif
