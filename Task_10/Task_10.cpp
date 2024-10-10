#include <iostream>

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
    double x1, x2, r, y1, y2, R, distance;
    std::cout << "Введите координаты и радиусы окружностей в следующем порядке: x1, y1, r, x2, y2, R: ";
    std::cin >> x1 >> y1 >> r >> x2 >> y2 >> R;
    distance = square_root((x1-x2)*(x1-x2) + (y1 - y2)*(y1-y2));
    if (distance > R + r)
        std::cout << "Ни одно условие не выполнено";
    else if(distance + r < R)
        std::cout << "Да";
    else if(distance + R < r)
        std::cout << "Да, но справедливо обратное";
    else 
        std::cout << "Фигуры пересекаются";
    return 0;
}