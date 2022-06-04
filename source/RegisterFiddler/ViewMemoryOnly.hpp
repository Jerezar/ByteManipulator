#ifndef FIDDLER_VIEWMEMORYSONLY_HPP
#define FIDDLER_VIEWMEMORYSONLY_HPP

#include "RegisterFiddlerView.hpp"

namespace register_fiddler{
    class ViewMemoryOnly: public RegisterFiddlerView{
        public:
            ViewMemoryOnly(RegFiddler _fiddler) : RegisterFiddlerView(_fiddler){};
            virtual std::string display() override;
    };
}
#endif
