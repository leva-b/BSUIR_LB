#include <iostream>
#include <cmath>
#include <string>


bool isLLRight(const std::string& input) {
    // Проверка на пустую строку или только минус
    if (input.empty() || (input == "-") || (input == "-")) {
        return false;
    }

    // Проверка на наличие дробной части
    if (input.find('.') != std::string::npos || input.find(',') != std::string::npos) {
        return false; // Дробное число
    }

    // Проверка на знак
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-') {
        start = 1; // Начинаем проверку с 1, чтобы пропустить знак
    }

    // Проверка на цифры
    for (size_t i = start; i < input.length(); ++i) {
        if (!isdigit(input[i])) {
            return false; // Не целое число
        }
    }

    // Проверка диапазона значений long long
    if (input.length() > 20) {
        return false; // Слишком длинная строка
    }

    // Сравнение со значениями LONG_LONG_MAX и LONG_LONG_MIN
    std::string longLongMax = std::to_string(std::numeric_limits<long long>::max());
    std::string longLongMin = std::to_string(std::numeric_limits<long long>::min());

    // Проверка для положительных значений
    if (input[0] == '+') {
        return input.length() < 20 || input <= longLongMax;
    }
    
    // Проверка для отрицательных значений
    if (input[0] == '-') {
        return input.length() < 20 || input <= longLongMin;
    }

    // Проверка для положительных значений без знака
    return input.length() < 19 || input <= longLongMax;
}

bool isIntRight(std::string& input) {
    // Проверка на пустую строку
    if (input.empty()) {
        return false;
    }

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

bool overflow(long long numberA, long long numberB){
    if (numberB > 0 && numberA > std::numeric_limits<long long>::max() - numberB) {
        return true;    }
    if (numberB < 0 && numberA < std::numeric_limits<long long>::min() - numberB) {
        return true; 
    }
    return false;
}
int main() {

    std::string strA, strN;
    bool flagStop = false;
    bool flag = true;
    long long a, n;
    long long sum = 0, number;
    while(true){
        sum = 0;
        number = 0;
        flag = true;
        std::cout << "Выполнил Левчишин Иван.\nГруппа-453505" << std::endl;
        std::cout << "\n" 
        <<"\n" 
        << "\n"
        << "" << std::endl;
        
        while(true){
            std::cout << "Введите колличества чисел ряда(n) для подсчета суммы sum = a - 2a + 4a -...+(-2)^(n-1)*a : ";
            std::getline(std::cin, strN);
            delSpace(strN);
            if (isLLRight(strN)){
                n = std::stoll(strN);
            }
            else{
                std::cout << "Введено некорректное значение или значение,превышающее предел. Пожалуйста повторите попытку ввода\n" << std::endl;
                continue;
            }
            if (n < 0){
                std::cout <<"Количество чисел ряда(n) не может быть отрицательным.\nПожалуйста, повторите попытку!\n" << std::endl;
            }
            else 
                break;
        }

        while(true){
            std::cout << "Введите целое число a для подсчета суммы ряда sum = a - 2a + 4a -...+(-2)^(n-1)*a : ";
            std::getline(std::cin, strA);
            delSpace(strA);
            if (isLLRight(strA)){
                a = std::stoll(strA);
            }
            else{
                std::cout << "Введено некорректное значение или значение,превышающее предел. Пожалуйста повторите попытку ввода\n" << std::endl;
                continue;
            }
            break;
        }
        sum = a;
        for(long long i = 1; i < n; ++i){
            /*if (powOverflow(-2, i)){
                system("clear");
                std::cout << "Сумма ряда превышает максимально допустимые значения. Пожалуйста повторите попытку ввода\n" << std::endl;
                flag = false;
                break;
            }*/
            number = pow(-2, i)*a;
            if (overflow(sum,number) || overflow(number,sum)){
                std::cout << "Сумма ряда превышает максимально допустимые значения. Пожалуйста повторите попытку ввода\n" << std::endl;
                flag = false;
                break;
            }
            sum += number;
        }
        if (flag == false)
            continue;
        
        std::cout << "Сумма ряда sum = a - 2a + 4a -...+(-2)^(n-1)*a при n = " << n << " и при а = " << a  << " равна sum = " << sum<< std::endl; 
        if (stopProgram(flagStop))
            break;
    }
    return 0;
}