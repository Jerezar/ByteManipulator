#ifndef REGFIDDLER_COMMAND_HPP
#define REGFIDDLER_COMMAND_HPP

#include "InstructionWrapper.hpp"
#include "RegisterFiddler/RegisterFiddler.hpp"
#include "GenericView.hpp"

namespace register_fiddler{
    /**
    * An Instruction acting specifically on a RegisterFiddler
    */
    class RegFiddlerCommand: virtual public InstructionWrapper{
        protected:
            RegFiddler fiddler;
            fw_byte_manip::View view;
        public:
            /**
            *@param _fiddler The target RegisterFiddler
            *@param _view The View that is returned after execution.
            */
            RegFiddlerCommand( RegFiddler _fiddler, fw_byte_manip::View _view){ fiddler = _fiddler;
            view = _view;};
    };
}
#endif
