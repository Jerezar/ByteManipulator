#ifndef FIDDLERLOGIC_HPP
#define FIDLLERLOGIC_HPP

#include "FiddlerNumericInput.hpp"


class FiddlerAnd: public FiddlerNumericInput{
    public:
        FiddlerAnd(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

class FiddlerOr: public FiddlerNumericInput{
    public:
        FiddlerOr(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

class FiddlerXor: public FiddlerNumericInput{
    public:
        FiddlerXor(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

class FiddlerXnor: public FiddlerNumericInput{
    public:
        FiddlerXnor(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif
