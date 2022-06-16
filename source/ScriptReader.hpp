#ifndef SCRIPTREADER_HPP
#define SCRIPTREADER_HPP

#include "InputOutputFacility.hpp"

#include <fstream>

class ScriptReader: public InputOutputFacility{
    private:
        std::fstream scriptFile;
    public:
        ScriptReader(std::string scriptPath);
        virtual std::string read(std::string prompt) override;
        virtual void print(std::string output) override;
};

#endif
