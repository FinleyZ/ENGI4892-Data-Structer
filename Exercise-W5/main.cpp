#include <iostream>

void recursive(int n){
    if (n == 0)
        return;
    int a;
    printf("%p\n", &a);
    recursive(n - 1);
}

int main() {
    recursive(5);


}