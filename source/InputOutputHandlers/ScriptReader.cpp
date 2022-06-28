#include "ScriptReader.hpp"

#include "ControlElement.hpp"

#include <iostream>

namespace fw_byte_manip{
    ScriptReader::ScriptReader(std::string scriptPath){
        scriptFile = std::fstream(scriptPath);
    }
    
    std::string ScriptReader::read(std::string prompt){
        (void) prompt;
        std::string line;
        
        if(!scriptFile.is_open() || scriptFile.eof()){
            return ControlElement::quit;
        }
        
        std::getline(scriptFile, line);
        return line;
    }
    
    /**
    * Prints to standard output.
    */
    void ScriptReader::print(std::string output){
        std::cout << output << std::endl;
    }
}
