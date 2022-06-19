#ifndef RUNSCRIPT_HPP
#define RUNSCRIPT_HPP

#include "InstructionWrapper.hpp"

#include "InstructionRegistry.hpp"

#include <memory>

/**
* An Instruction that reads a file line by line. Unlike the ScriptReader InputOutputHandler it does not end the execution loop when it reaches the end of the script.
* @warning There currently is no mechanism to prevent an infinite loop if executing a script that uses the RunScript command on itself. Therefor it may be better not to include this command in its own commandset.
*
*@warning There is also no mechanism to check if the target file is a valid script in the first place, possibly wasting a lot of time on larger files.
*/
class RunScript: virtual public InstructionWrapper{
    protected:
        InstructionSet commandSet;
    public:
        /**
        * @param _commandSet The other Instructions that can be executed by this Instruction.
        */
        RunScript(InstructionSet _commandSet){ commandSet = _commandSet; };
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif

