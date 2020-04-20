//
//  Lab13: Class Templates
//  Sarah Carter
//  CS202
//

#include <iostream>

//[ ] Write wrapper template class
//[ ] Write friend override operator << to work with wrapper

template <typename WrapType>
class Wrapper {
public:
    Wrapper(const WrapType& w) : obj_(w) {}
    
private:
    WrapType obj_;
};

int main(int argc, const char * argv[]) {
    Wrapper<int> {50};
    Wrapper<std::string> {"How many years I feel like I've been in isolation."};
    return 0;
}
