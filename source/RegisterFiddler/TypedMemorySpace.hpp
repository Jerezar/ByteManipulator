#ifndef FIDDLER_TYPEDMEMORYSPACE_HPP
#define FIDDLER_TYPEDMEMORYSPACE_HPP

#include "RegisterFiddler/MemorySpace.hpp"
#include "typedMemory.hpp"

namespace register_fiddler{
    /**
    * A MemBlock using an underlying instance of TypedMemory. It is therefor of a fixed size.
    */
    class TypedMemorySpace: public MemorySpace{
        private:
            TypedMemory mem;
        public:
            TypedMemorySpace(uint8_t defaultValue = 0);
            void set(unsigned int index, uint8_t value) override; 
            uint8_t get(unsigned int index) override;
            virtual unsigned int getSize() override;
    };
}

#endif
