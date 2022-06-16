#ifndef INPUTLOGGER_HPP
#define INPUTLOGGER_HPP

#include "InputOutputFacility.hpp"

#include <sstream>
namespace fw_byte_manip{
    class InputLogger: public InputOutputFacility{
        private:
            InputOutputHandler io;
            std::ostringstream fileContent;
            std::string filePath;
        public:
            InputLogger(InputOutputHandler _io, std::string _filePath = "./inputLog.txt");
            ~InputLogger();
            virtual std::string read(std::string prompt) override;
            virtual void print(std::string output) override;
    };
}

#endif
