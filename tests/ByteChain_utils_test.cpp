#include <catch2/catch_test_macros.hpp>

#include "RegisterFiddler/ByteChain_utils.cpp"


TEST_CASE("convert", ""){
    std::vector<uint32_t> first ( {0xcc76afFF, 0xf391adef, 0x3c38ff82, 0x41415e1c} );
    std::vector<uint8_t> prediction ( {0xcc, 0x76, 0xaf, 0xff, 0xf3, 0x91, 0xad, 0xef, 0x3c, 0x38, 0xff, 0x82, 0x41, 0x41, 0x5e, 0x1c} );
    std::vector<uint8_t> inter = register_fiddler::toByteVector<uint32_t>(first);
    
    REQUIRE(inter == prediction);
}

TEST_CASE("convert back", ""){
    std::vector<float> first ( {15.8, 300, 21.9, 90} );
    std::vector<uint8_t> inter = register_fiddler::toByteVector<float>(first);
    
    std::vector<float> second = register_fiddler::fromByteVector<float>(inter);
    
    REQUIRE(first == second);
}
