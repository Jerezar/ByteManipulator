#ifndef OUTPUTLOGGER_HPP
#define OUTPUTLOGGER_HPP

#include "InputOutputFacility.hpp"

namespace fw_byte_manip{
    class OutputLogger: public InputOutputFacility{
        private:
            InputOutputHandler io;
            std::string filePath;
            bool passthrough;
        public:
            OutputLogger(InputOutputHandler _io, std::string _filePath = "./outputLog.txt", bool _passthrough = true);
            virtual std::string read(std::string prompt) override;
            virtual void print(std::string output) override;
    };
}

#endif
