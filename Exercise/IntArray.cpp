#include <chrono>
#include <cstdlib>
#include <initializer_list>
#include <iostream>
#include <vector>
//what values did you choose? Why these values?
//I choose these value，
//10
//100
//500
//1000
//5000
//10000
//50000
//100000
//500000
//1000000
//5000000
//10000000
//Because the operation time is in direct proportion to the in direct proportion to WorkingSize.
//As WorkingSize getting larger, operation time getting longer.

using namespace std;

class IntegerArray {
public:
    IntegerArray() {
    }

    IntegerArray(std::initializer_list<int> init)
            : values_(init) {
    }

    IntegerArray(std::vector<int> &&v)
            : values_(std::move(v)) {
    }

    std::vector<int>::const_iterator begin() const {
        return values_.begin();
    }

    std::vector<int>::const_iterator end() const {
        return values_.end();
    }

    std::vector<int>::iterator insert(int v, size_t pos) {
        auto position = values_.begin() + pos;
        values_.insert(position, v);
    }

    IntegerArray &operator<<(int n) {
        values_.push_back(n);
        return *this;
    }

    size_t size() const {
        return values_.size();
    }

private:
    std::vector<int> values_;
};

std::ostream &operator<<(std::ostream &, const IntegerArray &);


// How many elements shall we store in our array?
constexpr size_t WorkingSize = 10000000;


int main(int, char *[]) {
    // Create an empty IntegerArray
    IntegerArray array;

    // Initialize random number generator
    srand(static_cast<unsigned int>(time(nullptr)));

    // Add random elements to the array
    for (size_t i = 0; i < WorkingSize; i++) {
        unsigned long r = static_cast<unsigned long>(rand());
        array << (r % WorkingSize);
    }

    //
    // Find an arbitrary number:
    //
    bool foundIt = false;
    int index = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (int value : array) {
        if (value == 42) {
            foundIt = true;
            break;
        }

        index++;
    }
    auto end = std::chrono::high_resolution_clock::now();

    if (foundIt) {
        cout << "found the value 42 at index " << index;
    } else {
        cout << "42 is not in the IntegerArray array";
    }

    cout << " (took " << (end - start).count() << " µs)\n";

    //
    // Find the largest number:
    //
    start = std::chrono::high_resolution_clock::now();
    int largest = 0;
    for (auto i = array.begin(); i != array.end(); i++) {
        if (*i > largest) {
            largest = *i;
        }
    }

    end = std::chrono::high_resolution_clock::now();

    cout << "the largest value is: " << largest
         << " (took " << (end - start).count() << " µs)\n";

    // insert a number at WorkingSize / 2
    start = std::chrono::high_resolution_clock::now();

    array.insert(10, WorkingSize / 2);

    end = std::chrono::high_resolution_clock::now();

    cout << "Insertion at WorkingSize /2 took " << (end - start).count() << " µs)\n";
    return 0;
}


std::ostream &operator<<(std::ostream &o, const IntegerArray &a) {
    o << "[";
    for (int i : a) {
        o << " " << i;
    }
    o << " ]\n";

    return o;
}
