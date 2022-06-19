#ifndef FIDDLER_MEMORYINTERPRETATION_HPP
#define FIDDLER_MEMORYINTERPRETATION_HPP

#include "RegisterFiddlerView.hpp"

namespace register_fiddler{
    /**
    * A View displaying the contents of the RegisterFiddler Memory interpreted as ASCII characters.
    */
    class MemoryInterpretationView: public RegisterFiddlerView{
        public:
            MemoryInterpretationView(RegFiddler _fiddler) : RegisterFiddlerView(_fiddler){};
            virtual std::string display() override;
    };
}
#endif
