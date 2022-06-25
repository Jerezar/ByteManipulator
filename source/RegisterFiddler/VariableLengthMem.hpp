#ifndef FIDDLER_VARIABLELENGTHMEM_HPP
#define FIDDLER_VARIABLELENGTHMEM_HPP

#include "RegisterFiddler/MemorySpace.hpp"
namespace register_fiddler{
    /**
    * MemBlocks that can add and remove capacity from themselves.
    */
    class VariableLengthMem: public MemorySpace{
        public:
            /**
            * Inserts a number of bytes following the specified index.
            */
            virtual void insert(unsigned int index, unsigned int length, uint8_t val = 0) = 0;
            
            /**
            * Removes a number of bytes following the specified index.
            */
            virtual void erase(unsigned int index, unsigned int length) = 0;
    };
}

#endif
