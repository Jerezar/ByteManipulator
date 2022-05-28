#ifndef REGISTERFIDDLER_MATHCOMMANDS_HPP
#define REGISTERFIDDLER_MATHCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{

    class Addition: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Addition(RegFiddler _fiddler, ValueParser _parser): RegFiddlerCommand(_fiddler), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
