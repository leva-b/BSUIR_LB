#include <iostream>
#include <cmath>

std::string delSpace(std::string& str){
    while (str.back() == ' ') {
        str.pop_back(); // Удаляет последний символ (пробел)
    }
    return str;
}

bool stopProgram(bool flagStop){
    std::string restart;

    while(true){
            std::cout << "Введите Y или y, если хотите перезапустить программу, и N или n, если хотите завершить выполнение программы: ";
            getline(std::cin, restart);
            delSpace(restart);
            if (restart == "Y" || restart == "y"){
                return flagStop;
            }else if(restart == "N" || restart == "n"){
                std::cout << "Выполнеие программы завершено.\nВыполнил Левчишин Иван.\nГруппа-453505";
                flagStop = true;
                break;
            }
            else {
                std::cout << "Что-то пошло не так, возможно введенное значение неверно:(\nПожалуйста повторите попытку.\n" << std::endl;
            }
        }

        return flagStop;

}

int main() {
    bool flagStop = false;
    double A = 0, B = M_PI/2, M = 20, H = (B - A)/M, x = A;
    double y;
    int i;
    while(true){

        std::cout << "Выполнил Левчишин Иван.\nГруппа-453505" << std::endl;
        std::cout << "Данная программа высчитывает значение функции y(x) = sin(x) - cos(x),\nгде x ∈ [0, PI/2], i - целочисленный коэфициент, i ∈ [0, 20]  H = PI/40\n";
        std::cout << "Значения yi = sin(x) - cos(x), при x = i * H равны:\n";

        x = A;
        for (i = 0; x <= B; i++, x += H){
            y = sin(x) - cos(x);
            std::cout << "y" << i << " = " << y << "\n";
        }

        if (stopProgram(flagStop))
                break;

    }
    return 0;
}