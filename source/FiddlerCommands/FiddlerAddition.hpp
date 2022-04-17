#ifndef FIDDLERADDITION_HPP
#define FIDLLERADDITION_HPP

#include "FiddlerCommand.hpp"

#include "NumberStringParser.hpp"

class FiddlerAddition: public FiddlerCommand{
    public:
        FiddlerAddition(Fiddler _target, ValueParser _parser): FiddlerCommand(_target){ parser = _parser;};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
