#ifndef FIDDLERAND_HPP
#define FIDLLERAND_HPP

#include "FiddlerNumericInput.hpp"


class FiddlerAnd: public FiddlerNumericInput{
    public:
        FiddlerAnd(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
