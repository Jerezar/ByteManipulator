#ifndef FIDDLERWRITE_HPP
#define FIDLLERWRITE_HPP

#include "FiddlerCommand.hpp"


class FiddlerWrite: public FiddlerCommand{
    public:
        FiddlerWrite(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerCommand(_target){ 
            parser = _parser;
            view = _view;
        };
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
