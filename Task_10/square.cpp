#include <iostream>
#include <cmath>

double square_root(double number){

    if (number == 0) 
        return 0;
    
    double square = number, xn;                  //задание начального приближения
    if (number > 1)
        xn = number / 2;
    else xn = 0.5;

    while (square - xn > 1e-7 || xn - square > 1e-7){
        xn = square;
        square = (xn + number/xn)/2; 
    }

    return square;
}
int main(){
    double x;
    std::cin >> x;
    std::cout << "square_root(x) = " << square_root(x) << " sqrt = " << sqrt(x);
    return 0;
}