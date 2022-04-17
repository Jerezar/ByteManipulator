#ifndef MOCKFIDDLERVIEW_HPP
#define MOCKFIDDLERVIEW_HPP

#include "MockFiddler.hpp"

#include <memory>

class MockFiddlerView{
    public:
        virtual static std::string display(Fiddler target) = 0;
};

using Mfd_View = std::shared_ptr<MockFiddlerView>;

#endif
