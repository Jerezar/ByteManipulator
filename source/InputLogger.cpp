#include "InputLogger.hpp"
#include <fstream>

namespace fw_byte_manip{
    InputLogger::InputLogger(InputOutputHandler _io, std::string _filePath){
        io = _io;
        filePath = _filePath;
    }
    
    InputLogger::~InputLogger(){
        std::fstream dstFile;
        dstFile.open(filePath, (std::ios_base::out | std::ios_base::trunc));
        
        dstFile << fileContent.str();
        
        dstFile.close();
    }
    
    std::string InputLogger::read(std::string prompt){
        std::string input = io->read(prompt);
        
        fileContent << input << std::endl;
        
        return input;
    }
    
    void InputLogger::print(std::string output){
        io->print(output);
    }
}
