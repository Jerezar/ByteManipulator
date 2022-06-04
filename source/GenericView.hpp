#ifndef GENERICVIEW_HPP
#define GENERICVIEW_HPP

#include <string>
#include <memory>

namespace fw_byte_manip {
    class GenericView{
        public:
            virtual std::string display() = 0;
    };
    
    using View = std::shared_ptr<GenericView>;
}
#endif
