#include <iostream>
#include <cmath>
#include <cstdint>

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

bool stopProgram(char restart_value, bool flagStop){
    std::string restart;

    while(true){
            std::cout << "Введите Y или y, если хотите перезапустить программу, и N или n, если хотите завершить выполнение программы: ";
            getline(std::cin, restart);
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

bool isInteger(const std::string& input) {
    
    if (input.empty() || (input == "-"))    // Проверяем, является ли строка целым числом
        return false;                       // Пустая строка или только минус
    
    if (input.find('.') != std::string::npos || input.find(',') != std::string::npos) { // Проверяем, есть ли дробная часть
        return false;                          // Дробное число
    }
    
    for (char c : input) {                  // Проверяем, что все символы - цифры
        if (!isdigit(c) && c != '-') {
            return false;                   // Не целое число
        }
    }
    return true;                            // Это целое число
}


int main() {
    std::string strNumberOfNumbers, strN;
    int numberOfNumbers, n;
    double x_value;
    char restart_value;
    bool flagStop;
    while(true){
        std::cout << "Вариант 9\nВыполнил Левчишин Иван.\nГруппа-453505" << std::endl;
        std::cout << "Данная программа находит значение функции с помощью разложения функции в ряд S(x),\nа затем находит и само значение функции Y(x)\n";
        std::cout << "Программа запрашивает у пользователя количество членов ряда (n),\nзатем просит у пользователя количество чисел, от которых он хочет посчитать функцию,\n" 
        << "затем пользователь вводит по одному числу (x от 0.1, до 1).\n"
        << "Программа считает значение функции с помощью ряда и с помощью стандартных функций и выводит оба значения.\n";
        flagStop = false;


        while(true){

            std::cout << "Введите количество членов ряда n такое, что 0 ≤ n ≤ 66: ";
            std::getline(std::cin, strN);
            if (isInteger(strN)){
                n = std::stoi(strN);
                break;
            }
            else if (n < 0){

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
            std::cin >> numberOfNumbers;
            if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
            {
                std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::cout << "Что-то пошло не так, возможно введенное значение неверно:(\nПожалуйста повторите попытку.\n" << std::endl;
            }else if (std::cin.peek() != '\n') {
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка оставшихся символов в буфере
                std::cout << "Ошибка: введены лишние символы! Пожалуйста, повторите попытку.\n" << std::endl;
            
            }else if (numberOfNumbers < 0){
                std::cout <<"Количество чисел, от которых вы хотите посчитать функцию не может быть отрицательным.\nПожалуйста, повторите попытку!\n" << std::endl;
            }
            else 
                break;
        }

        for(int i = 0; i < numberOfNumbers; ++i){
            while(true){
                std::cout << "Введите x для подчсета функции (x от 0.1, до 1): ";
                std::cin >> x_value;
                if (std::cin.fail()) // если предыдущее извлечение оказалось неудачным,
                {
                    std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    std::cout << "Что-то пошло не так, возможно введенное значение неверно:(\nПожалуйста повторите попытку.\n" << std::endl;
                }else if (std::cin.peek() != '\n') {
                
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистка оставшихся символов в буфере
                    std::cout << "Ошибка: введены лишние символы! Пожалуйста, повторите попытку.\n" << std::endl;
            
                }else if (x_value < 0.1 || x_value > 1){
                    std::cout << "Введено некорректное значение. Пожалуйста повторите попытку ввода\n" << std::endl;
                }
                else
                    break;
            }

            std::cout << "Результат разложения n членов функции равен: " 
            << decomposition(n, x_value) 
            << "\nЗначение функции с использованием стандартных библиотек: "<< Y(x_value) << std::endl;
        }

        if (stopProgram(restart_value, flagStop))
            break;
        
    } 
    return 0;
}