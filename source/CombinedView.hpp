#ifndef COMBINEDVIEW_HPP
#define COMBINEDVIEW_HPP

#include "GenericView.hpp"
#include <vector>

namespace fw_byte_manip {
    /**
    *A View that displays a number of subordinate Views in sequence.
    *
    *
    */
    class CombinedView: public GenericView{
        private:
            std::vector<View> views;
        public:
            /**
            * @param _views The subordinate Views in the order they are meant to be displayed.
            */
            CombinedView( std::vector<View> _views ) { views = _views; };
            virtual std::string display() override;
    };
}
#endif
