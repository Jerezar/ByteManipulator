#ifndef FIDDLERADDITION_HPP
#define FIDLLERADDITION_HPP

#include "FiddlerCommand.hpp"

class FiddlerAddition: public FiddlerCommand{
    public:
        FiddlerAddition(Fiddler _target): FiddlerCommand(_target){};
        virtual std::string execute(std::vector<std::string> args) override;
};

#endif
