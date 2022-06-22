#ifndef REGISTERFIDDLER_MISCCOMMANDS_HPP
#define REGISTERFIDDLER_MISCCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{
    /**
    * An Instruction that makes the RegisterFiddler move a value into the target register.
    */
    class Move: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Move(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), fw_byte_manip::NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * An Instruction that makes the RegisterFiddler negate the target register.
    */
    class Negate: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            Negate(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), fw_byte_manip::NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * An Instruction that toggles a bit in a register of a RegisterFiddler.
    */
    class ToggleBit: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            ToggleBit(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), fw_byte_manip::NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * An Instruction that makes the RegisterFiddler shift the target register in one direction.
    */
    class Shift: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            /**
            *@name directions
            *Decides in which direction to shift
            */
            /**@{*/
            static const std::string leftward;
            static const std::string rightward;
            /**@}*/
            
            Shift(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), fw_byte_manip::NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * An Instruction that makes the RegisterFiddler count the target register up or down.
    */
    class Count: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            /**
            *@name directions
            *Decides in which direction to count
            */
            /**@{*/
            static const std::string upward;
            static const std::string downward;
            /**@}*/
            
            Count(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), fw_byte_manip::NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
