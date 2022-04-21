#ifndef FIDDLERLEFTSHIFT_HPP
#define FIDDLERLEFTSHIFT_HPP

#include "FiddlerCommand.hpp"


class FiddlerLeftShift: public FiddlerCommand{
    public:
        FiddlerLeftShift(Fiddler _target, Mfd_View _view): FiddlerCommand(_target, _view){
        }
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif

