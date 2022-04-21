#ifndef FIDDLERRIGHTSHIFT_HPP
#define FIDDLERRIGHTSHIFT_HPP

#include "FiddlerCommand.hpp"


class FiddlerRightShift: public FiddlerCommand{
    public:
        FiddlerRightShift(Fiddler _target, Mfd_View _view): FiddlerCommand(_target, _view){
        }
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif

