#include <iostream>
#include <string>
#include <limits>

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
    int N, ai,  bi;
    bool flagStop = false;
    while (true){
        std::cout <<"\nВыполнил Левчишин Иван.\nГруппа-453505\n";
        std::cout << "Данная программа находит N = ∑ (ai − bi), где 1 ≤ i ≤ 30, a и b определены по формуле:\nai = {i, если i нечётное; i/2 , если i чётное}\nbi = {i^2, если i нечётное; i^3, если i чётное}"<<std::endl;
        N = 0;
        for (int i = 1; i <= 30; i++){
            ai = i % 2 == 1 ? i : i/2;
            bi = i % 2 == 1 ? i*i : i*i*i;
            N += (ai - bi)*(ai - bi); 
        }
        std::cout << "N = " << N << "\n";

        if (stopProgram(flagStop))
            break;
    }
    return 0;
}