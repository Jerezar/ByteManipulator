#include "InstructionSequence.hpp"

#include "string_utils.hpp"

namespace fw_byte_manip{
    std::string InstructionSequence::execute(std::vector<std::string> args){
        std::string result;
        for(std::vector<std::pair<Instruction, std::string>>::iterator iter = list.begin(); iter < list.end(); iter++){
             result += iter->first->execute( fw_byte_manip::string_utils::split( iter->second, " " )) +"\n";
        }
        return result;
    }
    std::string InstructionSequence::usage(){
        return "None";
    }
    
    void InstructionSequence::add(std::pair<Instruction, std::string> instruction){
        list.push_back(instruction);
    }
}
