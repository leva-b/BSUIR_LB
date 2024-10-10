#include <iostream>
#include <cmath>
#include <iomanip>

const double PI = 3.14159265358979323846;

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

double power(double x, int degree){
    double result = 1;
    for(int i = 1; i <=degree; i++){
        result *= x;
    }
    return result;
}

long long factorial(int x){
    long long result_fact = 1;
    for(int i = 2; i <= x; i++){
        result_fact *= i;
    }
    return result_fact;
}
double arcsin(double x){
    double res = x;
    for (int k = 1; k <= 60; k++){
        res += factorial(2*k)*power(x,2*k + 1)/power(4,k)/power(factorial(k),2)/(2*k+1); 
    }
    return res;
}

double arccos(double cos_value){
    if (cos_value >= 0.91)
        return square_root(2*(1-cos_value));
    else if(cos_value <= -0.91)
        return PI - square_root(2*(1 + cos_value));
    return PI/2 - arcsin(cos_value);
}

int main() {
    double x;
    int y;
    std::cin >> x;
    std::cout << std::setprecision(15) << "arccos(x) = " << arccos(x) << " acos(x) = " << acos(x);
    return 0;
}