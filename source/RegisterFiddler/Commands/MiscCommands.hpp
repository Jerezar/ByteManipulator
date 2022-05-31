#ifndef REGISTERFIDDLER_MISCCOMMANDS_HPP
#define REGISTERFIDDLER_MISCCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{

    class Move: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Move(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Negate: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Negate(RegFiddler _fiddler, RegFiddlerView _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
