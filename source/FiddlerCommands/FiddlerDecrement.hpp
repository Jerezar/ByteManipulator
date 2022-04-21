#ifndef FIDDLERDECREMENT_HPP
#define FIDDLERDECREMENT_HPP

#include "FiddlerCommand.hpp"


class FiddlerDecrement: public FiddlerCommand{
    public:
        FiddlerDecrement(Fiddler _target, Mfd_View _view): FiddlerCommand(_target, _view){
        }
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif

