#include "OutputLogger.hpp"
#include <fstream>

namespace fw_byte_manip{
    OutputLogger::OutputLogger(InputOutputHandler _io, std::string _filePath, bool _passthrough){
        io = _io;
        filePath = _filePath;
        passthrough = _passthrough;
    }
    
    std::string OutputLogger::read(std::string prompt){
        return io->read(prompt);
    }
    
    void OutputLogger::print(std::string output){
        std::fstream file(filePath, (std::ios_base::out | std::ios_base::app) );
        
        file << output << std::endl;
        if(passthrough){
            io->print(output);
        }
        file.close();
    }
}
