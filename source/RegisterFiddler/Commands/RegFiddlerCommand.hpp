#ifndef REGFIDDLER_COMMAND_HPP
#define REGFIDDLER_COMMAND_HPP

#include "InstructionWrapper.hpp"
#include "RegisterFiddler/RegisterFiddler.hpp"
#include "RegisterFiddler/RegisterFiddlerView.hpp"

namespace register_fiddler{
    class RegFiddlerCommand: virtual public InstructionWrapper{
        protected:
            RegFiddler fiddler;
            RegFiddlerView view;
        public:
            RegFiddlerCommand( RegFiddler _fiddler, RegFiddlerView _view){ fiddler = _fiddler;
            view = _view;};
    };
}
#endif
