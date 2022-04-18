#ifndef FIDDLERSET_HPP
#define FIDLLERSET_HPP

#include "FiddlerCommand.hpp"


class FiddlerSet: public FiddlerCommand{
    public:
        FiddlerSet(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerCommand(_target){ 
            parser = _parser;
            view = _view;
        };
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
