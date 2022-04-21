#ifndef FIDDLERAND_HPP
#define FIDLLERAND_HPP

#include "FiddlerMath.hpp"


class FiddlerAnd: public FiddlerMath{
    public:
        FiddlerAnd(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerMath(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
