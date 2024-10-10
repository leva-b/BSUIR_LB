#include <iostream>

int main() {
    int Y, N, a, b, c;
    std::cout << "Введите N, a, b, c: ";
    std::cin >> N >> a >> b >> c;
    switch(N){
        case 2:
            Y = b*c - a*a;
            break;
        case 3:
            Y = a - b*c;
            break;
        case 7:
            Y = a*a + c;
            break;
        case 56:
            Y = b*c;
            break;
        default:
        Y = (a+b)*(a+b)*(a+b);    
    }
    std::cout << "\n Y = " << Y;
    return 0;
}