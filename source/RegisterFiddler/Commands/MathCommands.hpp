#ifndef REGISTERFIDDLER_MATHCOMMANDS_HPP
#define REGISTERFIDDLER_MATHCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{

    class Addition: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Addition(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Subtraction: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Subtraction(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Multiplication: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Multiplication(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
