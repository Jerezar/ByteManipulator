#include "ScriptReader.hpp"

#include "ByteManipulator.hpp"

#include <iostream>

ScriptReader::ScriptReader(std::string scriptPath){
    scriptFile = std::fstream(scriptPath);
}

std::string ScriptReader::read(std::string prompt){
    (void) prompt;
    std::string line;
    
    if(!scriptFile.is_open() || scriptFile.eof()){
        return ByteManipulator::quit;
    }
    
    std::getline(scriptFile, line);
    return line;
}

void ScriptReader::print(std::string output){
    std::cout << output << std::endl;
}
