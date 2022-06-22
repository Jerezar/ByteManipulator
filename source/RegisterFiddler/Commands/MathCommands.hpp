#ifndef REGISTERFIDDLER_MATHCOMMANDS_HPP
#define REGISTERFIDDLER_MATHCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{
    /**
    * An Instruction that makes the RegisterFiddler add a value to the target register.
    */
    class Addition: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Addition(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * An Instruction that makes the RegisterFiddler subtract a value from the target register.
    */
    class Subtraction: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Subtraction(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * An Instruction that makes the RegisterFiddler multiply the target register by a value.
    */
    class Multiplication: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Multiplication(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * An Instruction that makes the RegisterFiddler divide the target register by a value.
    */
    class Division: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Division(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
