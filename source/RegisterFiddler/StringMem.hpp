#ifndef FIDDLER_STRINGMEM_HPP
#define FIDDLER_STRINGMEM_HPP

#include "RegisterFiddler/VariableLengthMem.hpp"

namespace register_fiddler{
    /**
    * A MemBlock using an underlying string. If a ByteChain larger than the remaining space is written into memory, memory is automatically extended.
    */
    class StringMem: public VariableLengthMem{
        private:
            std::string mem;
        public:
            StringMem(std::string init);
            void set(unsigned int index, uint8_t value) override; 
            uint8_t get(unsigned int index) override;
            virtual void write(ByteChain pat, unsigned int index, unsigned int maxLen = 0) override;
            virtual ByteChain read(unsigned int index, unsigned int len) override;
            virtual unsigned int getSize() override;
            
            void insert(unsigned int index, unsigned int length, uint8_t val) override;
            void erase(unsigned int index, unsigned int length) override;
    };
}

#endif
