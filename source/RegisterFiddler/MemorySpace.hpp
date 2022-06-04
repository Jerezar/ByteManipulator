#ifndef FIDDLER_MEMORYSPACE_HPP
#define FIDDLER_MEMORYSPACE_HPP

#include <memory>

namespace register_fiddler{
    class MemorySpace{
        public:
            virtual void set(unsigned int index, uint8_t value) = 0;
            virtual uint8_t get(unsigned int index) = 0;
            virtual unsigned int getSize() = 0;
    };
    
    using MemBlock = std::shared_ptr<MemorySpace>;
}
#endif
