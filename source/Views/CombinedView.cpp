#include "CombinedView.hpp"

namespace fw_byte_manip {
    std::string CombinedView::display(){
        std::string result;
        for(std::vector<View>::iterator iter = views.begin(); iter < views.end(); iter++){
            result += (*iter)->display();
        }
        return result;
    }
}
