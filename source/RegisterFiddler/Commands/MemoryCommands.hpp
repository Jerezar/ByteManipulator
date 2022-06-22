#ifndef REGISTERFIDDLER_MEMORYCOMMANDS_HPP
#define REGISTERFIDDLER_MEMORYCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{
    /**
    * An Instruction that makes the RegisterFiddler load a byte from memory into a register.
    */
    class Load: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Load(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), fw_byte_manip::NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * An Instruction that makes the RegisterFiddler save a byte from a register into memory.
    */
    class Save: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Save(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), fw_byte_manip::NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}

#endif
