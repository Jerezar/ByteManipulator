#ifndef INSTRUCTIONWRAPPER_HPP
#define INSTRUCTIONWRAPPER_HPP
#include <string>
#include <vector>
#include <memory>

class InstructionWrapper{
    public:
        virtual std::string execute(std::vector<std::string> args) = 0;
        virtual std::string usage(){ return std::string("unspecified");};
};

using Instruction = std::shared_ptr<InstructionWrapper>;
#endif
