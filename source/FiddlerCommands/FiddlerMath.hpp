#ifndef FIDDLERMATH_HPP
#define FIDLLERMATH_HPP

#include "FiddlerNumericInput.hpp"


class FiddlerAddition: public FiddlerNumericInput{
    public:
        FiddlerAddition(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

class FiddlerSubtraction: public FiddlerNumericInput{
    public:
        FiddlerSubtraction(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

class FiddlerMultiplication: public FiddlerNumericInput{
    public:
        FiddlerMultiplication(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

class FiddlerDivision: public FiddlerNumericInput{
    public:
        FiddlerDivision(Fiddler _target, ValueParser _parser, Mfd_View _view): FiddlerNumericInput(_target, _view, _parser){};
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};



#endif
