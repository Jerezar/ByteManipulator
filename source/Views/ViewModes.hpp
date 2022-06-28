#ifndef VIEWMODES_HPP
#define VIEWMODES_HPP

#include "GenericView.hpp"
#include <map>
#include <vector>

namespace fw_byte_manip {
    /**
    * A View that can switch between several named subordinate Views
    */
    class ViewModes: public GenericView{
        private:
            /**
            * The View that will be displayed with display().
            */
            View activeView;
            
            /**
            * The pairs of names and Views to which can be switched.
            */
            std::map< std::string, View> views;
        public:
            /**
            *@param _views A map of names and corresponding Views. The View with the first name in alphabetical order will be the first active View.
            */
            ViewModes( std::map< std::string, View> _views );
            
            /**
            *@param _views A map of names and corresponding Views.
            *@param first The name of the View which is to be the first active View.
            */
            ViewModes( std::map< std::string, View> _views, std::string first);
            virtual std::string display() override;
            
            /**
            * @returns The list with the names of all possible Views that can be switched to.
            */
            std::vector< std::string> getNames();
            
            /**
            * Changes activeView to be the View with the specified name. If there is no View with this name nothing happens.
            * @param name The name of the View
            */
            void setActive(std::string name);
    };
}
#endif
