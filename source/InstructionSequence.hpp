#ifndef INSTRUCTIONSEQUENCE_HPP
#define INSTRUCTIONSEQUENCE_HPP

#include "InstructionWrapper.hpp"

namespace fw_byte_manip{
    class InstructionSequence : public InstructionWrapper{
        private:
            std::vector<std::pair<Instruction, std::string>> list;
        public:
            InstructionSequence( std::vector< std::pair< Instruction, std::string > > _list = std::vector< std::pair< Instruction, std::string > >()) { list = _list; };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };
}

#endif
