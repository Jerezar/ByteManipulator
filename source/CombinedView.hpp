#ifndef COMBINEDVIEW_HPP
#define COMBINEDVIEW_HPP

#include "GenericView.hpp"
#include <vector>

namespace fw_byte_manip {
    class CombinedView: public GenericView{
        private:
            std::vector<View> views;
        public:
            CombinedView( std::vector<View> _views ) { views = _views; };
            virtual std::string display() override;
    };
}
#endif
