#include <iostream>

int main() {
    double x, x_2, a, b;
    std::cout << "Введите x: ";
    std::cin >> x;
    x_2 = x*x;
    a = (23*x_2 + 32) * x;
    b = 69*x_2 + 8;
    std::cout << "23x^3 + 69x^2 + 32x + 8 = " << a+b << "\n";
    std::cout <<  "-23x^3 + 69x^2 - 32x + 8 = " << b-a;
    return 0;
}