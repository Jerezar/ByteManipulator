#include <catch2/catch_test_macros.hpp>

#include "StringNumberConverter.hpp"

TEST_CASE("", "[Binary]"){
    SECTION( "Correct conversion" ){
        uint8_t result1 = StringNumberConverter::getBinaryFromString("0b11");

        REQUIRE(result1 == 3 );
    }
    
    SECTION( "Overly long values get truncated" ){
        uint8_t result1 = StringNumberConverter::getBinaryFromString("0b1100101101001");

        REQUIRE(result1 == 0b01101001 );
    }
    
    SECTION( "Leading zeroes do not change result" ){
        uint8_t result1 = StringNumberConverter::getBinaryFromString("0b000101");
        uint8_t result2 = StringNumberConverter::getBinaryFromString("0b101");

        REQUIRE(result1 == result2 );
    }
    
    /*
    SECTION( "Invalid input " ){
        REQUIRE_THROWS_AS(
            StringNumberConverter::getBinaryFromString("2555"), 
            StringNumberConverter::InvalidInputException
        );
    }
    */
}

TEST_CASE("", "[Decimal]"){
    SECTION( "Correct conversion" ){
        uint8_t result1 = StringNumberConverter::getDecimalFromString("240");

        REQUIRE(result1 == 240 );
    }
    
    SECTION( "Overly long values get truncated" ){
        uint8_t result1 = StringNumberConverter::getDecimalFromString("6505");

        REQUIRE(result1 == 0b01101001 );
    }
    
    SECTION( "Leading zeroes do not change result" ){
        uint8_t result1 = StringNumberConverter::getDecimalFromString("00032");
        uint8_t result2 = StringNumberConverter::getDecimalFromString("32");

        REQUIRE(result1 == result2 );
    }
    
    /*
    SECTION( "Invalid input " ){
        REQUIRE_THROWS_AS(
            StringNumberConverter::getBinaryFromString("2555"), 
            StringNumberConverter::InvalidInputException
        );
    }
    */
}

TEST_CASE("", "[Octal]"){
    SECTION( "Correct conversion" ){
        uint8_t result1 = StringNumberConverter::getOctalFromString("0O74");

        REQUIRE(result1 == 60 );
    }
    
    SECTION( "Overly long values get truncated" ){
        uint8_t result1 = StringNumberConverter::getOctalFromString("0o14551");

        REQUIRE(result1 == 0b01101001 );
    }
    
    SECTION( "Leading zeroes do not change result" ){
        uint8_t result1 = StringNumberConverter::getOctalFromString("0o0032");
        uint8_t result2 = StringNumberConverter::getOctalFromString("0o32");

        REQUIRE(result1 == result2 );
    }
    
    /*
    SECTION( "Invalid input " ){
        REQUIRE_THROWS_AS(
            StringNumberConverter::getBinaryFromString("2555"), 
            StringNumberConverter::InvalidInputException
        );
    }
    */
}

TEST_CASE("", "[Hex]"){
    SECTION( "Correct conversion" ){
        uint8_t result1 = StringNumberConverter::getHexFromString("0xFF");

        REQUIRE(result1 == 0b11111111 );
    }
    
    SECTION( "Overly long values get truncated" ){
        uint8_t result1 = StringNumberConverter::getHexFromString("0xFBAC");

        REQUIRE(result1 == 0xAC );
    }
    
    SECTION( "Leading zeroes do not change result" ){
        uint8_t result1 = StringNumberConverter::getHexFromString("0X8");
        uint8_t result2 = StringNumberConverter::getHexFromString("0x008");

        REQUIRE(result1 == result2 );
    }
    
    /*
    SECTION( "Invalid input " ){
        REQUIRE_THROWS_AS(
            StringNumberConverter::getBinaryFromString("2555"), 
            StringNumberConverter::InvalidInputException
        );
    }
    */
}
