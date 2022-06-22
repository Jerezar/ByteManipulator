#ifndef INSTRUCTIONMAP_HPP
#define INSTRUCTIONMAP_HPP

#include "InstructionRegistry.hpp"
#include "InstructionWrapper.hpp"

#include <map>

namespace fw_byte_manip{
    /**
    * Keeps Instructions in a map
    */
    class InstructionMap: public InstructionRegistry{
        private:
            std::map<std::string, Instruction> instructions;
        public:
            /**
            * @param commands The initial map of Instructions with their names
            */
            InstructionMap(std::map<std::string, Instruction> commands);
            virtual Instruction getInstruction(std::string name) override;
            virtual std::string help() override;
            /**
            * Adds a new Instruction to the map.
            */
            void registerInstruction(std::string name, Instruction instr);
            /**
            * Adds multiple new Instructions to the map
            */
            void registerInstruction(std::map<std::string, Instruction> commands);
    };
}
#endif
