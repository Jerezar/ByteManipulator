#include <catch2/catch_test_macros.hpp>

#include "RegisterFiddler/ByteChain.hpp"
#include <algorithm>

TEST_CASE("Construction from Vector", "[]"){
    std::vector<uint8_t> input( {120, 250, 130, 23, 16} );
    register_fiddler::ByteChain test(input);
    
    REQUIRE(test.size() == input.size());
    REQUIRE(test.getBytes() == input);
}

TEST_CASE("Copy-Construction", "[]"){
    std::vector<uint8_t> input( {120, 250, 130, 23, 16} );
    register_fiddler::ByteChain test1(input);
    
    register_fiddler::ByteChain test2(test1);
    
    
    
    REQUIRE(test1.size() == test2.size());
    REQUIRE(test1.getBytes() == test2.getBytes());
}

TEST_CASE("Created from Type", "[]"){
    unsigned long long first = 0x00afe9da120400ff;
    register_fiddler::ByteChain test(&first, sizeof(unsigned long long));
    std::vector<uint8_t> prediction({0x00, 0xaf, 0xe9, 0xda, 0x12, 0x04, 0x00, 0xff});
    
    //This was written on a little-endian system
    std::reverse(prediction.begin(), prediction.end());
    
    REQUIRE(test.size() == sizeof(unsigned long long));
    REQUIRE(test.getBytes() == prediction);
}

TEST_CASE("Properly dumped Type", "[]"){
    SECTION("Integer"){
        int first = 100;
        int second = 0;
        
        register_fiddler::ByteChain test(&first, sizeof(int));
        
        test.dump(&second, sizeof(int));
        
        REQUIRE(first == second);
    }
    
    SECTION("Float"){
        float first = 130.500;
        float second = 0;
        
        register_fiddler::ByteChain test(&first, sizeof(float));
        
        test.dump(&second, sizeof(float));
        
        REQUIRE(first == second);
    }
}
