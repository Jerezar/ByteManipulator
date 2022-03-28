#ifndef INSTRUCTIONREGISTRY_HPP
#define INSTRUCTIONREGISTRY_HPP
#include "InstructionWrapper.hpp"
#include <memory>
#include <string>

class InstructionRegistry{
    public:
        virtual Instruction getInstruction(std::string name) = 0;
};

using InstructionSet = std::shared_ptr<InstructionRegistry>;

#endif
