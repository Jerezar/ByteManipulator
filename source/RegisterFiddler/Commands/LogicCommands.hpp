#ifndef REGISTERFIDDLER_LOGICCOMMANDS_HPP
#define REGISTERFIDDLER_LOGICCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{
    /**
    * Instruction that makes the RegisterFiddler to apply a bitwise 'and' to the target register based on the value.
    */
    class And: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            And(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * Instruction that makes the RegisterFiddler to apply a bitwise 'or' to the target register based on the value.
    */
    class Or: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Or(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * Instruction that makes the RegisterFiddler to apply a bitwise 'xor' to the target register based on the value.
    */
    class Xor: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Xor(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * Instruction that makes the RegisterFiddler to apply a bitwise 'xnor' to the target register based on the value.
    */
    class Xnor: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Xnor(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
