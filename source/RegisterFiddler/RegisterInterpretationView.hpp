#ifndef FIDDLER_REGISTERINTERPRETATIONVIEW_HPP
#define FIDDLER_REGISTERINTERPRETATIONVIEW_HPP

#include "RegisterFiddlerView.hpp"

namespace register_fiddler{
    class RegisterInterpretationView: public RegisterFiddlerView{
        public:
            RegisterInterpretationView(RegFiddler _fiddler) : RegisterFiddlerView(_fiddler){};
            virtual std::string display() override;
    };
}
#endif
