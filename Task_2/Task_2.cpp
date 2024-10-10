#include <iostream>

int main() {
    double x, y, z;
    std::cin >> x >> y >> z;
    x+y>z && x+z>y && z+y>x?std::cout << "YES" :std::cout << "NO";
    // put your code here
    return 0;
}