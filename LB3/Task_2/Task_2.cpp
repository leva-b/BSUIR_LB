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

    double e = 1e-3, sum, dn, n;
    bool flagStop = false;

    while(true){

        n = 0;
        sum = 0;

        std::cout << "\nВыполнил Левчишин Иван.\nГруппа-453505\n";
        std::cout << "Данная программа найходит сумму ряда с точностью ε = 10^(−3), общий член которого dn = 1/2^n + 1/3^n.\n";
        std::cout << "Точность достигнута, если dn < ε\n";
        do{
            dn = 1/pow(2,n) + 1/pow(3,n);
            sum += dn;
            n++;
        }while (dn >= e);
        std::cout << "Сумма ряда с точностью 10^(-3) равна " << sum << std::endl;

        if (stopProgram(flagStop))
            break;
    }
    return 0;
}