#ifndef FIDDLERXOR_HPP
#define FIDLLERXOR_HPP

#include "FiddlerMath.hpp"


class FiddlerXor: public FiddlerMath{
    public:
        FiddlerXor(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerMath(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
