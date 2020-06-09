#include <iostream>
#include "remove.h"

int main() {
    //!Time the execution of RemoveMultOf10
    list<int> li = {10,1,2,3,20,4,45,5,600};

    auto startFunction  = chrono::high_resolution_clock::now();
    RemoveMultOf10(li);
    auto endFunction = chrono::high_resolution_clock::now();
    std::cout<< "RemoveMultOf10 with size: "<< li.size()
        <<", in " << (endFunction - startFunction).count() << " ns\n";

    //!Time the execution of RemoveSameNumber
    std::vector<int> vec = {2,5,6,2,4,6,7,5,2};

    startFunction  = chrono::high_resolution_clock::now();
    RemoveSameNumber(vec);
    endFunction = chrono::high_resolution_clock::now();
    std::cout<< "RemoveSameNumber with size: "<< vec.size()
    <<", in " << (endFunction - startFunction).count() << " ns\n";







    return 0;
}
