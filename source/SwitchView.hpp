#ifndef SWITCHVIEW_HPP
#define SWITCHVIEW_HPP

#include "InstructionWrapper.hpp"

#include "ViewModes.hpp"
namespace fw_byte_manip {
    class SwitchView: virtual public InstructionWrapper{
        protected:
            std::shared_ptr<ViewModes> view;
        public:
            static const std::string listOption;
            SwitchView(std::shared_ptr<ViewModes> _view){
                view = _view;
            };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };

}

#endif
