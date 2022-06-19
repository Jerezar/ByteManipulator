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

std::string InstructionMap::help(){
    std::string result;
    for(std::map<std::string, Instruction>::iterator it = this->instructions.begin();
        it != this->instructions.end();
        it++){
        result += it->first + "\t" + it->second->usage() + "\n";
    }
    
    return result;
}

/**
* @note Equivalent to calling the other registerInstruction(std::map<std::string, Instruction> commands) with a map of one.
*/
void InstructionMap::registerInstruction(std::string name, Instruction instr){
    this->registerInstruction( { {name, instr} } );
}

/**
* If a new Instruction has the same name as a previous one it will not be added.
*/
void InstructionMap::registerInstruction(std::map<std::string, Instruction> commands){
    this->instructions.merge(commands);
}
