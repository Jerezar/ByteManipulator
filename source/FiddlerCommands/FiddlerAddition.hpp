#ifndef FIDDLERADDITION_HPP
#define FIDLLERADDITION_HPP

#include "FiddlerMath.hpp"


class FiddlerAddition: public FiddlerMath{
    public:
        FiddlerAddition(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerMath(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
