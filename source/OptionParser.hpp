#ifndef BYTEMANIPULATOR_OPTIONPARSER_HPP
#define BYTEMANIPULATOR_OPTIONPARSER_HPP

#include <map>
#include <vector>
#include <string>

namespace fw_byte_manip{
    class OptionParser{
        private:
            static const std::string prefix;
            std::map<std::string, unsigned int> options;
        public:
            void addOption(std::string name, unsigned int numArgs = 0);
            bool isOption(std::string arg);
            std::map<std::string, std::vector< std::vector< std::string> > > parseArguments(std::vector<std::string> args, int skip = 1);
    };
}

#endif
