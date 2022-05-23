#ifndef INSTRUCTIONMAP_HPP
#define INSTRUCTIONMAP_HPP

#include "InstructionRegistry.hpp"
#include "InstructionWrapper.hpp"

#include <map>

class InstructionMap: public InstructionRegistry{
    private:
        std::map<std::string, Instruction> instructions;
    public:
        InstructionMap(std::map<std::string, Instruction> commands);
        virtual Instruction getInstruction(std::string name) override;
        virtual std::string help() override;
        void registerInstruction(std::string name, Instruction instr);
        void registerInstruction(std::map<std::string, Instruction> commands);
};

#endif
