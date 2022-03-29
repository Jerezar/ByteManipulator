#include "string_utils.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("string wird korrekt aufgeteilt?", "[split]"){
    std::string sentence("Dies ist ein Platzhalter");
    
    std::vector< std::string > words;
    
    SECTION( "Geteilt an Muster mit Länge 1" ){
        words = split(sentence, " ");
        
        REQUIRE(words.size() == 4);
        REQUIRE(words[0] == "Dies");
        REQUIRE(words[1] == "ist");
        REQUIRE(words[2] == "ein");
        REQUIRE(words[3] == "Platzhalter");
    }
    
    SECTION( "Geteilt an Muster mit Länge 3" ){
        words = split(sentence, "ein");
        
        REQUIRE(words.size() == 2);
        REQUIRE(words[0] == "Dies ist ");
        REQUIRE(words[1] == " Platzhalter");
    }
}
