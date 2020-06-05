#include <iostream>
#include "remove.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    list<int> li = {1,2,3,4,45,5};
    listRemove(li);
    return 0;
}
