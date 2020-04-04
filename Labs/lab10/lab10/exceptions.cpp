#include <iostream>

void functionC()
{
  //your code here
}

void functionB()
{
  //your code here
  std::cout << "Starting functionB()\n";
  functionC();
  std::cout << "Ending functionB()\n";
}

void functionA()
{
  // your code here
    try {
        functionB();
        std::cout << "This code should not be reached.\n";
    }
  // your code here
    catch(const std::exception& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
    std::cout << "This code should be reached.\n";
  // your code here
}

int main()
{
  std::cout << "Starting main()" << std::endl;
  functionA();
  std::cout << "Ended normally." << std::endl;
  return 0;
}
