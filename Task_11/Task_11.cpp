#include <iostream>

int main(){
    int h1, min1, h2, min2, hd, mind;
    std::cin >> h1 >> min1 >> h2 >> min2;
    min1 += h1*60;
    min2 += h2*60;
    if (min2 < min1)
        mind = 24*60 - min1 + min2;
    else mind = min2 - min1;
    hd = mind / 60;
    mind %= 60;
    std::cout << "Студент работал "<< hd << " часов " << mind << " минут";
    return 0;
}