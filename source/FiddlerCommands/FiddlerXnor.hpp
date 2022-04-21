#ifndef FIDDLERXNOR_HPP
#define FIDLLERXNOR_HPP

#include "FiddlerMath.hpp"


class FiddlerXnor: public FiddlerMath{
    public:
        FiddlerXnor(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerMath(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
