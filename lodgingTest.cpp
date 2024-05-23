#include <iostream>
#include <cassert>
#include "lodging.h"

int main() {
    
  std::cout << "Testing started." << std::endl;
    Lodging objectTest("Los Angeles", 5, 5);
    assert(objectTest.getDuration() == 5);
    
  std::cout << "..." << std::endl;
  std::cout << "Testing finished. 0 errors" << std::endl;









    return 0;
}