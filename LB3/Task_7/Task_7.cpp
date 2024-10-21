#include <iostream>
#include <cmath>
#include <string>

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
    std::string strNumber;
    bool flagStop = false;
    int number, j;
    while(true){
        j = 1;
        std::cout << "Выполнил Левчишин Иван.\nГруппа-453505" << std::endl;
        std::cout << "Числа Армстронга (названные в честь Майкла Ф. Армстронга (Michael F. Armstrong)), их также называют самовлюбленными числами\n" 
        <<"и совершенными цифровыми инвариантами, – это числа, равные сумме своих цифр, возведенных в степень, равную \n" 
        << "количеству цифр. Например, наименьшее число Армстронга – 153, которое равно 1^3 + 5^3 + 3^3.\n"
        << "Данная программа, выводит все числа Армстронга, меньше введённого пользователем числа." << std::endl;
        while (true){
            std::cout << "Введите число для нахождения всех чисел Армстронга, меньше введенного: ";
            std::getline(std::cin, strNumber);
            delSpace(strNumber);
            if (isIntRight(strNumber)){
                number = std::stoi(strNumber);
                if (number <= 0){
                    std::cout << "Введенное число должно быть больше нуля.\n";
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
        std::cout << "Числа Армстронга меньше введенного:\n";
        while(j<number){
            int armstr_number = j, i = 1, sum = 0;
            while(armstr_number  % (int)pow(10,i) != armstr_number)i++; 
            for(int k = 1;k <= i;k++){
                sum+= pow(armstr_number % 10,i);
                armstr_number /= 10;
            }
            if (sum == j ) std::cout << j << "\n";
            j++;
        }

        if (stopProgram(flagStop))
            break;
    }
    return 0;
}