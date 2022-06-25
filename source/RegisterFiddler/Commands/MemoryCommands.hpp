#ifndef REGISTERFIDDLER_MEMORYCOMMANDS_HPP
#define REGISTERFIDDLER_MEMORYCOMMANDS_HPP

#include "RegisterFiddler/Commands/RegFiddlerCommand.hpp"
#include "NumericInputCommand.hpp"
#include "RegisterFiddler/VariableLengthMem.hpp"

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
    
    class Write: public RegFiddlerCommand, public fw_byte_manip::NumericInputCommand{
        public:
            static const std::string listOption;
            static const std::vector<std::string> types;
            Write(RegFiddler _fiddler, fw_byte_manip::View _view, ValueParser _parser): RegFiddlerCommand(_fiddler, _view), fw_byte_manip::NumericInputCommand(_parser){};
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    
    /**
    * Instruction that erases a span of memory from a VariableLengthMem object.
    */
    class Erase: public fw_byte_manip::NumericInputCommand{
        private:
            std::shared_ptr<VariableLengthMem> mem;
            fw_byte_manip::View view;
        public:
            Erase(std::shared_ptr<VariableLengthMem> _mem, fw_byte_manip::View _view, ValueParser _parser): fw_byte_manip::NumericInputCommand(_parser) { mem = _mem; view = _view; };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    /**
    * Instruction that erases a span of memory from a VariableLengthMem object.
    */
    class Insert: public fw_byte_manip::NumericInputCommand{
        private:
            std::shared_ptr<VariableLengthMem> mem;
            fw_byte_manip::View view;
        public:
            Insert(std::shared_ptr<VariableLengthMem> _mem, fw_byte_manip::View _view, ValueParser _parser): fw_byte_manip::NumericInputCommand(_parser) { mem = _mem; view = _view; };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
    
    class DumpMemory : public RegFiddlerCommand{
        protected:
            std::string defaultPath;
        public:
            /**
            * @param _view The View that is meant to be printed into the file
            * @param path The path of the file that will be printed into, as long as no other path is passed as an argument
            */
            DumpMemory(RegFiddler _fiddler, fw_byte_manip::View _view, std::string path = "./FiddlerMemory.bin"): RegFiddlerCommand(_fiddler, _view){
                defaultPath = path;
            };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}

#endif
