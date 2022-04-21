#ifndef FIDDLERMATH_HPP
#define FIDDLERMATH_HPP

#include "FiddlerCommand.hpp"


#include "NumberStringParser.hpp"

class FiddlerMath: public FiddlerCommand{
    protected:
        ValueParser parser;
    public:
        FiddlerMath(Fiddler _target, Mfd_View _view, ValueParser _parser): FiddlerCommand(_target, _view){
            parser = _parser;
        }
};

#endif

