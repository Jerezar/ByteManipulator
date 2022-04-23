#ifndef MEMORYCOMMAND_HPP
#define MEMORYCOMMAND_HPP

#include "InstructionWrapper.hpp"
#include "typedMemory.hpp"
#include <memory>


class MemoryCommand: virtual public InstructionWrapper{
    protected:
        std::shared_ptr<TypedMemory> mem;
    public:
        MemoryCommand(std::shared_ptr<TypedMemory> _mem){
            mem = _mem;
        }
};

#endif

