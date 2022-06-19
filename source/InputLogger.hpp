#ifndef INPUTLOGGER_HPP
#define INPUTLOGGER_HPP

#include "InputOutputFacility.hpp"

#include <sstream>
namespace fw_byte_manip{
    /**
    * An InputOutputHandler decorator that prints all lines of input into a text file.
    * The file can be run as a script to redo a session. 
    */
    class InputLogger: public InputOutputFacility{
        private:
            /**
            * The InputOutputHandler from which the input is taken.
            */
            InputOutputHandler io;
            /**
            * The input accumulating over a session.
            */
            std::ostringstream fileContent;
            /**
            * The path to the target file. 
            */
            std::string filePath;
        public:
            /**
            * @param _io The source InputOutputHandler.
            * @param _filePath The target file.
            */
            InputLogger(InputOutputHandler _io, std::string _filePath = "./inputLog.txt");
            ~InputLogger();
            virtual std::string read(std::string prompt) override;
            virtual void print(std::string output) override;
    };
}

#endif
