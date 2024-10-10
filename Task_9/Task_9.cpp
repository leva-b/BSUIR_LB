#include <iostream>
#include <cmath>

int main(){

    int N;
    double x, z, b, a, func, Y;
    
    std::cout << "Введите значения b, a, z: ";
    std::cin >> b >> a >> z;
    x = z<= 0 ? z*z/2 : sqrt(z);

    std::cout << "Выберите номер функции:\n1)f(x) = 2x\n2)f(x) = x^3\n3)f(x) = x/3\n";
    std::cin >> N;

    switch(N){
        case 1:
            func = 2*x;
            std::cout << "Вы выбрали функцию f(x) = 2x\n";
            break;
        case 2:
            func = x*x*x;
            std::cout << "Вы выбрали функцию f(x) = x^3\n";
            break;
        case 3:
            func = x/3;
            std::cout << "Вы выбрали функцию f(x) = x/3\n";
            break;
        default:
            std::cout << "Нет такого номера функции, попробуйте еще раз";
            return 0;
    }

    Y = b*func/cos(x) + a*log(fabs(tan(x/2)));
    std:: cout << "\n Y = " << Y;
    return 0;
}