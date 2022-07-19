#ifndef BYTEMANIPULATOR_INPUTPREPROCESSOR_HPP
#define BYTEMANIPULATOR_INPUTPREPROCESSOR_HPP

#include <memory>
#include <vector>
#include <string>

namespace fw_byte_manip{
    class InputPreprocessor{
        public:
            virtual std::vector< std::string > parse( std::string input ) = 0;
    };
    
    using Preprocessor = std::shared_ptr<InputPreprocessor>;
}

#endif
