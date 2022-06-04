#ifndef REGISTERFIDDLER_MEMORYCOMMANDS_HPP
#define REGISTERFIDDLER_MEMORYCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{

    class Load: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Load(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Save: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Save(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}

#endif
