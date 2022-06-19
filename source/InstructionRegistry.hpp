#ifndef INSTRUCTIONREGISTRY_HPP
#define INSTRUCTIONREGISTRY_HPP
#include "InstructionWrapper.hpp"
#include <memory>
#include <string>

/**
* An object that knows a number of Instructions and can return them by their name.
*/
class InstructionRegistry{
    public:
        /**
        * @param name The name of the target Instruction.
        * @returns The Instruction with the passed name.
        */
        virtual Instruction getInstruction(std::string name) = 0;
        virtual std::string help() = 0;
};

using InstructionSet = std::shared_ptr<InstructionRegistry>;

#endif
