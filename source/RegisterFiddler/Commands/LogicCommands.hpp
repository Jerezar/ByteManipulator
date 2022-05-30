#ifndef REGISTERFIDDLER_LOGICCOMMANDS_HPP
#define REGISTERFIDDLER_LOGICCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{

    class And: public RegFiddlerCommand, public NumericInputCommand{
        public:
            And(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Or: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Or(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Xor: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Xor(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Xnor: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Xnor(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
