#ifndef VIEWMODES_HPP
#define VIEWMODES_HPP

#include "GenericView.hpp"
#include <map>
#include <vector>

namespace fw_byte_manip {
    class ViewModes: public GenericView{
        private:
            View activeView;
            std::map< std::string, View> views;
        public:
            ViewModes( std::map< std::string, View> _views );
            ViewModes( std::map< std::string, View> _views, std::string first);
            virtual std::string display() override;
            std::vector< std::string> getNames();
            void setActive(std::string name);
    };
}
#endif
