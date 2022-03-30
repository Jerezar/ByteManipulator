#include "InstructionMap.hpp"

#include <memory>
#include "NoOperation.hpp"

InstructionMap::InstructionMap(std::map<std::string, Instruction> commands){
    this->instructions = commands;
}

Instruction InstructionMap::getInstruction(std::string name) {
    std::map<std::string, Instruction>::iterator it = this->instructions.find(name);
    if( it == instructions.end()){
        return std::make_shared<NoOperation>();
    } else {
        return it->second;
    }
}

void InstructionMap::registerInstruction(std::string name, Instruction instr){
    this->instructions[name] = instr;
}
