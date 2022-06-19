#ifndef GENERICVIEW_HPP
#define GENERICVIEW_HPP

#include <string>
#include <memory>

namespace fw_byte_manip {
    /**
    * Displays something as a string.
    */
    class GenericView{
        public:
            /**
            * @returns Whatever is meant to be displayed as a string.
            */
            virtual std::string display() = 0;
    };
    
    using View = std::shared_ptr<GenericView>;
}
#endif
