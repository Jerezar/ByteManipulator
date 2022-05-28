#ifndef REGFIDDLER_COMMAND_HPP
#define REGFIDDLER_COMMAND_HPP

#include "InstructionWrapper.hpp"
#include "RegisterFiddler/RegisterFiddler.hpp"

namespace register_fiddler{
    class RegFiddlerCommand: virtual public InstructionWrapper{
        protected:
            RegFiddler fiddler;
        public:
            RegFiddlerCommand( RegFiddler _fiddler){ fiddler = _fiddler; };
    };
}
#endif
