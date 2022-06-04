#ifndef REGFIDDLER_COMMAND_HPP
#define REGFIDDLER_COMMAND_HPP

#include "InstructionWrapper.hpp"
#include "RegisterFiddler/RegisterFiddler.hpp"
#include "GenericView.hpp"

namespace register_fiddler{
    class RegFiddlerCommand: virtual public InstructionWrapper{
        protected:
            RegFiddler fiddler;
            fw_byte_manip::View view;
        public:
            RegFiddlerCommand( RegFiddler _fiddler, fw_byte_manip::View _view){ fiddler = _fiddler;
            view = _view;};
    };
}
#endif
