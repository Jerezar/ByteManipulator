#ifndef FIDDLER_VIEWREGISTERSONLY_HPP
#define FIDDLER_VIEWREGISTERSONLY_HPP

#include "RegisterFiddlerView.hpp"

namespace register_fiddler{
    /**
    * A View that display the bitpatterns in the registers of a RegisterFiddler, as well the flag byte.
    */
    class ViewRegistersOnly: public RegisterFiddlerView{
        public:
            ViewRegistersOnly(RegFiddler _fiddler) : RegisterFiddlerView(_fiddler){};
            virtual std::string display() override;
    };
}
#endif
