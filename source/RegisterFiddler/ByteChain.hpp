#ifndef FIDDLER_BYTECHAIN_HPP
#define FIDDLER_BYTECHAIN_HPP

#include <vector>
#include <stdint.h>

namespace register_fiddler{
    class ByteChain{
        private:
            std::vector<uint8_t> bytes;
            
        public:
            ByteChain(std::vector<uint8_t> _bytes);
            ByteChain(const ByteChain& b);
            ByteChain(void* src, int size);
            
            void dump(void* dest, int size);
            
            /**
            * Read-only access
            */
            const uint8_t& operator[](unsigned int index) const;
            
            std::vector<uint8_t> getBytes() const;
            
            unsigned int size() const;
    };
}
#endif
