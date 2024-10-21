#include <iostream>
#include <limits>
#include <cmath>

std::string delSpace(std::string& str){
    while (str.back() == ' ') {
        str.pop_back(); // Удаляет последний символ (пробел)
    }
    return str;
}

bool isIntRight(std::string& input) {
    // Проверка на пустую строку
    if (input.empty()) {
        return false;
    }
    if (input.back() == ' ') 
        input.pop_back();
    // Проверка на знак
    size_t startIndex = 0;
    if (input[0] == '-' || input[0] == '+') {
        startIndex = 1;
    }

    // Проверка длины
    if (input.length() - startIndex > 10) {
        return false; // Длина больше 10 для положительных чисел (макс 2147483647)
    }

    // Проверка на максимальное значение
    if (input.length() - startIndex == 10) {
        std::string maxIntStr = (input[0] == '-') ? "2147483648" : "2147483647";
        if (input.compare(startIndex, 10, maxIntStr.substr(1)) > 0) {
            return false; // Сравнение строк
        }
    }

    // Проверка, что все остальные символы являются цифрами
    for (size_t i = startIndex; i < input.length(); ++i) {
        if (!isdigit(input[i])) {
            return false; // Не цифра
        }
    }

    return true;
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
    double x;
    bool flagStop = false;
    long double fstep;
    double minY, valueY;
    double res;
    int numberOfSpaces; 
    std::string strNumberOfSpaces;
    while(true){

        std::cout << "Вариант 9\nВыполнил Левчишин Иван.\nГруппа-453505" << std::endl;
        std::cout << "Данная программа находит приближенное значение уравнения lg(cosh(x)) - tanh(x) + 0.5 = 0\n";
        std::cout << "Корень находится по следующему алгоритму: перебираем значения от начала \n"
        <<"до конца интервала с некоторым шагом и ищем значение функции, минимальное по модулю.\n"
        << "Аргумент, при котором оно достигается, считаем корнем уравнения. Программа запрашивает\n"
        <<"у пользователя, на сколько частей разделить область поиска корня, вычислияет шаг,\n"
        <<"с которым нужно проходить значения, проходит в цикле нужные значения, находит корень и выводит его.";
        

        res = 0;
        x = 0;
        valueY = log10(cosh(x)) - sinh(x) + 0.5;
        if (valueY < 0)
            minY = -valueY;
        else
            minY = valueY;
        

        while (true){
            std::cout << "На сколько областей разделить область X ∈ [0;2] для приближенного поиска корня уравнения lg(cosh(x)) - tanh(x) + 0.5 = 0: ";
            std::getline(std::cin, strNumberOfSpaces);
            delSpace(strNumberOfSpaces);
            if (isIntRight(strNumberOfSpaces)){
                numberOfSpaces = std::stoi(strNumberOfSpaces);
                if (numberOfSpaces <= 0){
                std::cout << "Количество количество областей для поиска корня не может быть меньше или равно нулю.\n";
                std::cout << "Пожалуйста, повторите попытку!\n" << std::endl;
                }
                else 
                    break;
            
            
            }
            else{
                std::cout << "Введено некорректное значение или значение превышающие границы типа int. Пожалуйста повторите попытку ввода\n" << std::endl;
                continue;
            }
            
        }
        fstep = 2. / (numberOfSpaces - 1);

        for (unsigned int i = 0; x <= 2; i++){
            x += fstep; 
            valueY = log10(cosh(x)) - sinh(x) + 0.5;
            if (valueY < 0)
                valueY = -valueY;
            if (valueY < minY){
                minY = valueY;
                res = x;
            }
        }
        std::cout << "Приближенный корень уравнения равен: " << res <<"\n";

        if (stopProgram(flagStop))
            break;
        
    } 
    return 0;
}