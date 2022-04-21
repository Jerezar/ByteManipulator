#ifndef FIDDLERMULTIPLICATION_HPP
#define FIDLLERMULTIPLICAION_HPP

#include "FiddlerMath.hpp"


class FiddlerMultiplication: public FiddlerMath{
    public:
        FiddlerMultiplication(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerMath(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
