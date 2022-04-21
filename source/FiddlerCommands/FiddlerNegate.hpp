#ifndef FIDDLERNEGATE_HPP
#define FIDDLERNEGATE_HPP

#include "FiddlerCommand.hpp"


class FiddlerNegate: public FiddlerCommand{
    public:
        FiddlerNegate(Fiddler _target, Mfd_View _view): FiddlerCommand(_target, _view){
        }
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif

