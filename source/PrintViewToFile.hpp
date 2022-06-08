#ifndef PRINTVIEWTOFILE_HPP
#define PRINTVIEWTOFILE_HPP

#include "InstructionWrapper.hpp"

#include "GenericView.hpp"
namespace fw_byte_manip {
    class PrintViewToFile: virtual public InstructionWrapper{
        protected:
            View view;
            std::string defaultPath;
        public:
            PrintViewToFile(View _view, std::string path = "./PrintViewToFile.txt"){
                defaultPath = path;
                view = _view;
            };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };

}

#endif
