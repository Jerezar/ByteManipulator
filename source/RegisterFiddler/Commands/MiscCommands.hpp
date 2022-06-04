#ifndef REGISTERFIDDLER_MISCCOMMANDS_HPP
#define REGISTERFIDDLER_MISCCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"

namespace register_fiddler{

    class Move: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Move(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Negate: public RegFiddlerCommand, public NumericInputCommand{
        public:
            Negate(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    class ToggleBit: public RegFiddlerCommand, public NumericInputCommand{
        public:
            ToggleBit(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Shift: public RegFiddlerCommand, public NumericInputCommand{
        public:
            static const std::string leftward;
            static const std::string rightward;
            
            Shift(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    class Count: public RegFiddlerCommand, public NumericInputCommand{
        public:
            static const std::string upward;
            static const std::string downward;
            
            Count(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}
#endif
