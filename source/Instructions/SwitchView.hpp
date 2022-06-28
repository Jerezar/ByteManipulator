#ifndef SWITCHVIEW_HPP
#define SWITCHVIEW_HPP

#include "InstructionWrapper.hpp"

#include "Views/ViewModes.hpp"
namespace fw_byte_manip {
    /**
    * An Instruction that makes a ViewModes object switch between active Views.
    */
    class SwitchView: virtual public InstructionWrapper{
        protected:
            std::shared_ptr<ViewModes> view;
        public:
            /**
            * If this is the input the Instruction will instead list out the names of all possible Views for the target 
            */
            static const std::string listOption;
            
            /**
            * @param _view The target ViewModes object
            */
            SwitchView(std::shared_ptr<ViewModes> _view){
                view = _view;
            };
            virtual std::string execute(std::vector<std::string> args) override;
            virtual std::string usage() override;
    };

}

#endif
