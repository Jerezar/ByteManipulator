#include "InputLogger.hpp"
#include <fstream>

namespace fw_byte_manip{
    InputLogger::InputLogger(InputOutputHandler _io, std::string _filePath){
        io = _io;
        filePath = _filePath;
    }
    
    /**
    * When the object gets destroyed it dumps the accumulated into the target file. If the target file already exists it is overwritten.
    * @note This was done to prevent an infinite loop specifically when using the RunScript command on the inputlog. It does not solve this problem in other contexts, so this should be changed.
    */
    InputLogger::~InputLogger(){
        std::fstream dstFile;
        dstFile.open(filePath, (std::ios_base::out | std::ios_base::trunc));
        
        dstFile << fileContent.str();
        
        dstFile.close();
    }
    
    /**
    * Prints the input into the accumulation stream and passes it to the underlying InputOutputHandler.
    */
    std::string InputLogger::read(std::string prompt){
        std::string input = io->read(prompt);
        
        fileContent << input << std::endl;
        
        return input;
    }
    
    /**
    * Simply passes it to the underlying InputOutputHandler.
    */
    void InputLogger::print(std::string output){
        io->print(output);
    }
}
