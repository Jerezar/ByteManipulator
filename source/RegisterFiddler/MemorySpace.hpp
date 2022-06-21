#ifndef FIDDLER_MEMORYSPACE_HPP
#define FIDDLER_MEMORYSPACE_HPP

#include <memory>
#include "ByteChain.hpp"

namespace register_fiddler{
    /**
    * A container for bytes that can be retrieved and deposited, but not immediately modified.
    */
    class MemorySpace{
        public:
            /**
            * Places a single byte-sized value in memory.
            */
            virtual void set(unsigned int index, uint8_t value) = 0;
            /**
            * Gets a single byte-sized value from memory.
            */
            virtual uint8_t get(unsigned int index) = 0;
            
            /**
            * Places multiple bytes in memory.
            */
            virtual void write(ByteChain pat, unsigned int index, unsigned int maxLen = 0) = 0;
            
            /**
            * Reads multiple bytes from memory.
            */
            virtual ByteChain read(unsigned int index, unsigned int len) = 0;
            /**
            * Gets the size of memory object.
            */
            virtual unsigned int getSize() = 0;
    };
    
    using MemBlock = std::shared_ptr<MemorySpace>;
}
#endif
