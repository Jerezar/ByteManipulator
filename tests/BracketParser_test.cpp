#include <catch2/catch_test_macros.hpp>
#include "BracketParser.hpp"

TEST_CASE("Wird an Whitespace aufgetrennt?", "[split]"){
    std::string input("this is a splittable string");
    std::vector< std::string > prediction({"this", "is", "a", "splittable", "string"});
    
    fw_byte_manip::BracketParser parser;
    
    REQUIRE(parser.parse(input) == prediction);
}

TEST_CASE("Whitespacelänge veränert nicht das Ergebnis?", "[split]"){
    std::string input("    this\tis\ta splittable\vstring   ");
    
    std::vector< std::string > prediction({"this", "is", "a", "splittable", "string"});
    
    fw_byte_manip::BracketParser parser;
    
    REQUIRE(parser.parse(input) == prediction);
}

TEST_CASE("Whitespace zwischen zwei Anführungszeichen wird als Teildes Wortes angesehen?", "[split]"){
    std::string input("this should split \"Dies aber nicht\" this should again\n");
    std::vector< std::string > prediction({"this", "should", "split", "Dies aber nicht", "this", "should", "again"});
    
    fw_byte_manip::BracketParser parser;
    
    REQUIRE(parser.parse(input) == prediction);
}

TEST_CASE("Klammern des selben Typs können in einander liegen?", "[split]"){
    std::string input("[test [not ended] ] {geschweifte {klammer} } (not (broken) )");
    std::vector< std::string > prediction ({ "test [not ended] ", "geschweifte {klammer} ", "not (broken) " });
    
    fw_byte_manip::BracketParser parser;
    
    REQUIRE(parser.parse(input) == prediction);
}
