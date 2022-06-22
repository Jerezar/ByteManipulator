#ifndef FIDDLERNUMERICINPUT_HPP
#define FIDDLERNUMERICINPUT_HPP

#include "FiddlerCommand.hpp"


#include "NumericInputCommand.hpp"

class FiddlerNumericInput: public FiddlerCommand, public fw_byte_manip::NumericInputCommand{

    public:
        FiddlerNumericInput(Fiddler _target, Mfd_View _view, ValueParser _parser): FiddlerCommand(_target, _view), NumericInputCommand(_parser){}
};

#endif

