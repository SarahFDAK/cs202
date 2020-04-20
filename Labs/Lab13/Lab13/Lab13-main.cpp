//
//  Lab13: Class Templates
//  Sarah Carter
//  CS202
//

#include <iostream>

//[x] Write wrapper template class
//[x] Write friend override operator << to work with wrapper

template <typename WrapType>
class Wrapper {
public:
    Wrapper(const WrapType& w) : obj_(w) {}
    
private:
    WrapType obj_;
    
    template <typename T>
    friend std::ostream& operator<< (std::ostream& os, const Wrapper<T>& mything);
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Wrapper<T>& mything) {
    os << mything.obj_;
    return os;
}

int main(int argc, const char * argv[]) {
    Wrapper<int> days{50};
    Wrapper<std::string> whining{"How many years I feel like I've been in isolation."};
    std::cout << days << ": " << whining << std::endl;
    return 0;
}
