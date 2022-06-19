#ifndef OUTPUTLOGGER_HPP
#define OUTPUTLOGGER_HPP

#include "InputOutputFacility.hpp"

namespace fw_byte_manip{
    /**
    *  An InputOutputHandler decorator that prints the output into a text file.
    */
    class OutputLogger: public InputOutputFacility{
        private:
            /**
            * The underlying InputOutputHandler.
            */
            InputOutputHandler io;
            /**
            * The path to the target file.
            */
            std::string filePath;
            /**
            * Whether or not to pass the output to the underlying InputOutputHandler (default) or simply block it.
            */
            bool passthrough;
        public:
            OutputLogger(InputOutputHandler _io, std::string _filePath = "./outputLog.txt", bool _passthrough = true);
            virtual std::string read(std::string prompt) override;
            virtual void print(std::string output) override;
    };
}

#endif
