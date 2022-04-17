#ifndef MOCKFIDDLER_HPP
#define MOCKFIDDLER_HPP

#include <stdint.h>

#include <memory>

struct MockFiddler{
    uint8_t byte;
    bool carry = false;
};

using Fiddler = std::shared_ptr<MockFiddler>;

#endif
