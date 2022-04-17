#ifndef MOCKFIDDLER_HPP
#define MOCKFIDDLER_HPP

#include <stdint.h>

#include <memory>

struct MockFiddler{
    uint8_t byte;
    bool carry = false;
    bool zero;
    bool parity;
    void updateParity(){
        bool result = true;
        for (int i = 0; i < 8; i++){
            if((byte & (1 << i))){
                result = !result;
            }
        }
        parity = result;
    };
};

using Fiddler = std::shared_ptr<MockFiddler>;

#endif
