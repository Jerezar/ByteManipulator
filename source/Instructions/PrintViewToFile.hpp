#ifndef PRINTVIEWTOFILE_HPP
#define PRINTVIEWTOFILE_HPP

#include "InstructionWrapper.hpp"

#include "GenericView.hpp"
namespace fw_byte_manip {
    /**
    * An Instruction that prints what a View would display to a file.
    */
    class PrintViewToFile: virtual public InstructionWrapper{
        protected:
            View view;
            std::string defaultPath;
        public:
            /**
            * @param _view The View that is meant to be printed into the file
            * @param path The path of the file that will be printed into, as long as no other path is passed as an argument
            */
            PrintViewToFile(View _view, std::string path = "./PrintViewToFile.txt"){
                defaultPath = path;
                view = _view;
            };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };

}

#endif
