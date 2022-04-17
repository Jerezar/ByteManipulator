#ifndef MOCKFIDDLERVIEW_HPP
#define MOCKFIDDLERVIEW_HPP

#include "MockFiddler.hpp"

class MockFiddlerView{
    public:
        virtual static std::string display(Fiddler target) = 0;
};

#endif
