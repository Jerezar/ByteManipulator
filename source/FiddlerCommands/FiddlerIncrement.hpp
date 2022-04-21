#ifndef FIDDLERINCREMENT_HPP
#define FIDDLERINCREMENT_HPP

#include "FiddlerCommand.hpp"


class FiddlerIncrement: public FiddlerCommand{
    public:
        FiddlerIncrement(Fiddler _target, Mfd_View _view): FiddlerCommand(_target, _view){
        }
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif

