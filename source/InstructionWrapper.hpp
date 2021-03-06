#ifndef INSTRUCTIONWRAPPER_HPP
#define INSTRUCTIONWRAPPER_HPP
#include <string>
#include <vector>
#include <memory>

namespace fw_byte_manip{
    struct ErrorMessage{
        ErrorMessage(std::string _kind, std::string _desc) { kind = _kind; desc = _desc; };
        std::string kind;
        std::string desc;
        std::string to_string(){ return kind + "\n\t" + desc + "\n";};
    };
    
    /**
    * An object that executes an action based on a list of strings.
    */
    class InstructionWrapper{
        public:
            /**
            * Takes a list of arguments and does something based on them.
            * @note Much like commandline arguments, the first entry in the list is the name used to call the command. It should as such be ignored in the execution of the command itself.
            */
            virtual std::string execute(std::vector<std::string> args) = 0;
            virtual std::string usage(){ return std::string("unspecified");};
    };
    
    using Instruction = std::shared_ptr<InstructionWrapper>;
}
#endif
