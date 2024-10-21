#include <iostream>
#include <cmath>
#include <cstdint>
#include <limits>

std::string delSpace(std::string& str){
    while (str.back() == ' ') {
        str.pop_back(); // Удаляет последний символ (пробел)
    }
    return str;
}

long long factorial(int number){
    long long result = 1;
    if (number == 0 || number == 1) return result;
    for(int i = 2; i <= number; ++i){
        result *= i;
    }
    return result;
}

long double decomposition(int quantity, double x){
    long double sum = 1;
    unsigned long long factN = 1;
    long double degree = 1;
    for(int n = 1; n < quantity; n++){
        factN *= n;
        degree *= x/2;
        sum += (n*n + 1)/factN*degree;
    }
    return sum;
}

double Y(double x){
    return((x*x/4 + x/2 + 1)*pow(M_E,x/2));
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

bool isIntRight(const std::string& input) {
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

bool isLLRight(const std::string& input) {
    // Проверка на пустую строку или только минус
    if (input.empty() || (input == "-")) {
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

std::string commaReplacement(const std::string& input) {
    std::string result = input; // Создаем копию входной строки

    size_t pos = result.find(','); // Ищем первую запятую
    if (pos != std::string::npos) {
        result[pos] = '.'; // Заменяем запятую на точку
    }

    return result; // Возвращаем результат
}

bool isLDRight(const std::string& input) {
    // Проверка на пустую строку
    if (input.empty()) return false;

    // Проверка, что все символы - цифры, знак минус, или точка
    bool decimalPointFound = false;
    for (char c : input) {
        if (!isdigit(c) && c != '-' && c != '.' && c != 'e' && c != 'E' && c != '+' ) {
            return false;
        }
        if (c == '.') {
            if (decimalPointFound) return false; // Более одной точки
            decimalPointFound = true;
        }
    }

    // Преобразование строки в long double
    char* end;
    long double value = strtold(input.c_str(), &end);

    // Проверка, что преобразование завершилось корректно
    if (*end != '\0') return false; // Остались лишние символы
    if (value == HUGE_VAL || value == -HUGE_VAL) return false; // Переполнение

    // Проверка на диапазон значений long double
    if (value < std::numeric_limits<long double>::lowest() || value > std::numeric_limits<long double>::max()) {
        return false; // Выход за пределы диапазона
    }

    return true;
}

int main() {
    std::string strNumberOfNumbers, strN, strX_value;
    long long numberOfNumbers;
    int n;
    long double x_value;
    bool flagStop = false;
    while(true){
        std::cout << "\nВариант 9\nВыполнил Левчишин Иван.\nГруппа-453505" << std::endl;
        std::cout << "Данная программа находит значение функции с помощью разложения функции в ряд S(x),\nа затем находит и само значение функции Y(x)\n";
        std::cout << "Программа запрашивает у пользователя количество членов ряда (n),\nзатем просит у пользователя количество чисел, от которых он хочет посчитать функцию,\n" 
        << "затем пользователь вводит по одному числу (x от 0.1, до 1).\n"
        << "Программа считает значение функции с помощью ряда и с помощью стандартных функций и выводит оба значения.\n";


        while(true){

            std::cout << "Введите количество членов ряда n (n - целое число) такое, что 0 ≤ n ≤ 66: ";
            std::getline(std::cin, strN);
            delSpace(strN);
            if (isIntRight(strN)){
                n = std::stoi(strN);
            }
            else{
                std::cout << "Введено некорректное значение. Пожалуйста повторите попытку ввода\n" << std::endl;
                continue;
            }
            if (n < 0){

                std::cout << "Количество членов ряда не может быть отрицательным.\n";
                std::cout << "Пожалуйста, повторите попытку!\n" << std::endl;
            
            }else if (n > 66){

            std::cout <<"Введенное количество членов ряда слишком большое\n";
            std::cout << "(Для поиска каждого члена ряда необходимо посчитать его логарифм).\n";
            std::cout <<"Пожалуйста, повторите попытку!\n" << std::endl;

            }else
                break;
        }
        while(true){
            std::cout << "Введите количество чисел, от которых Вы хотите посчитать функцию, заданное число не может быть меньше нуля: ";
            std::getline(std::cin, strNumberOfNumbers);
            delSpace(strNumberOfNumbers);
            if (isLLRight(strNumberOfNumbers)){
                numberOfNumbers = std::stoll(strNumberOfNumbers);
            }
            else{
                std::cout << "Введено некорректное значение или значение,превышающее предел. Пожалуйста повторите попытку ввода\n" << std::endl;
                continue;
            }
            if (numberOfNumbers < 0){
                std::cout <<"Количество чисел, от которых вы хотите посчитать функцию не может быть отрицательным.\nПожалуйста, повторите попытку!\n" << std::endl;
            }
            else 
                break;
        }

        for(int i = 0; i < numberOfNumbers; ++i){
            while(true){
                std::cout << "Введите x для подчсета функции (x от 0.1, до 1): ";
                std::getline(std::cin, strX_value);
                delSpace(strX_value);
                if (isLDRight(commaReplacement(strX_value))){
                    strX_value = commaReplacement(strX_value);
                    x_value = std::stold(strX_value);
                }
                else{
                    std::cout << "Введено некорректное значение или значение превышающее предел. Пожалуйста повторите попытку ввода\n" << std::endl;
                    continue;
                }
                if (x_value < 0.099999999999999997888 || x_value > 1){
                    std::cout << "Введено некорректное значение или значение превышающее предел. Пожалуйста повторите попытку ввода\n" << std::endl;
                }
                else
                    break;
            }

            std::cout << "Результат разложения n членов функции равен: " 
            << decomposition(n, x_value) 
            << "\nЗначение функции с использованием стандартных библиотек: "<< Y(x_value) << std::endl;
        }

        if (stopProgram(flagStop))
            break;
        
    }
    return 0;
}