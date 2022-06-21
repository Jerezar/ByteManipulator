#include <catch2/catch_test_macros.hpp>

#include "RegisterFiddler/ByteChain.hpp"

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
    
    REQUIRE(test.size() == sizeof(unsigned long long));
    REQUIRE(test[0] == 0xff);
    REQUIRE(test[1] == 0x00);
    REQUIRE(test[2] == 0x04);
    REQUIRE(test[3] == 0x12);
    REQUIRE(test[4] == 0xda);
    REQUIRE(test[5] == 0xe9);
    REQUIRE(test[6] == 0xaf);
    REQUIRE(test[7] == 0x00);
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
