#ifndef SCRIPTREADER_HPP
#define SCRIPTREADER_HPP

#include "InputOutputFacility.hpp"

#include <fstream>

namespace fw_byte_manip{

    /**
    * Reads a file line by line.
    */
    class ScriptReader: public InputOutputFacility{
        private:
            std::fstream scriptFile;
        public:
            /**
            * @param scriptPath The file from which to read.
            */
            ScriptReader(std::string scriptPath);
            virtual std::string read(std::string prompt) override;
            virtual void print(std::string output) override;
    };
}

#endif
