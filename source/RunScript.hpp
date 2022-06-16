#ifndef RUNSCRIPT_HPP
#define RUNSCRIPT_HPP

#include "InstructionWrapper.hpp"

#include "InstructionRegistry.hpp"

#include <memory>

class RunScript: virtual public InstructionWrapper{
    protected:
        InstructionSet commandSet;
    public:
        RunScript(InstructionSet _commandSet){ commandSet = _commandSet; };
        virtual std::string execute(std::vector<std::string> args) override;
        virtual std::string usage() override;
};

#endif

