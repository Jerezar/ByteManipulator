#ifndef FIDDLER_MEMFLOATVIEW_HPP
#define FIDDLER_MEMFLOATVIEW_HPP

#include "RegisterFiddlerView.hpp"

namespace register_fiddler{
    /**
    * A View that displays the contents of a RegisterFiddlers memory as single-precision floats.
    */
    class MemFloatView: public RegisterFiddlerView{
        public:
            MemFloatView(RegFiddler _fiddler) : RegisterFiddlerView(_fiddler){};
            virtual std::string display() override;
    };
}
#endif
