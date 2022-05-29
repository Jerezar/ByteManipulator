#ifndef FIDDLER_VIEWREGISTERSONLY_HPP
#define FIDDLER_VIEWREGISTERSONLY_HPP

#include "RegisterFiddlerView.hpp"

namespace register_fiddler{
    class ViewRegistersOnly: public RegisterFiddlerView{
        public:
            ViewRegistersOnly(){};
            virtual std::string display() override;
    };
}
#endif
