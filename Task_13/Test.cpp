#include <iostream>

double binpow(double a, int n) {
    std::cout << "x = " << a << "\n";
    std::cout << "y = " << n << "\n";
    if(n < 0){
        a = 1/a;
        n = -n;
    }
    double res = 1;
    std::cout << "result = " << res << "\n";
    while (n != 0) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
        std::cout << "x = " << a << "\n" << "y = " << n << "\n";
        std::cout << "result = " << res << "\n"; 
    }
    return res;
}

int main(){
    int x, y, z;
    std::cout << "Введите два целых числа ";
    std::cin >> x >> y;
    z = binpow(x,y);
    std::cout << "Результат возведения числа " << x << " в степень " << y << " равен " << z;
    return 0;
}