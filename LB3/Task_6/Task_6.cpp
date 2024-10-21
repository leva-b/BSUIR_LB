#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

const double PI = 3.14159265358979323846;
const double E = 2.718281828459045;

std::string delSpace(std::string& str){
    while (str.back() == ' ') {
        str.pop_back(); 
    }
    return str;
}

std::string commaReplacement(const std::string& input) {
    std::string result = input; 

    size_t pos = result.find(','); // Ищем первую запятую
    if (pos != std::string::npos) {
        result[pos] = '.'; 
    }

    return result;
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

long double reducingArgument(long double argument){

    long double x_7;
    std::ostringstream oss;
    std::string strNum;
    long double y;
    long double convertedNum;
    while(argument > 1e17){
        oss << std::fixed << std::setprecision(0) << argument/7;  
        strNum = oss.str();  
        std::istringstream iss(strNum);
        iss >> x_7;
        oss.str(""); // Очищает содержимое потока   
        oss.clear(); // Сбрасывает состояние потока
       
        argument -= x_7*2*PI;
    }
    
    if(argument > 2*PI){
        
        y = argument/(2*PI);
        oss << std::fixed << std::setprecision(0) << argument/(2*PI);  
        strNum = oss.str();  
        std::istringstream iss(strNum);
        iss >> convertedNum; 
        
    }

    return (y-convertedNum)*2*PI; 
}

double my_sin(double x){

    int signd = 1;
    if (x < 0){
        x =-x;
        signd *= -1;
    }
    if (x > 2*PI){
        x = reducingArgument(x);
    }
    if (x > PI){
        x -= PI;
        signd *= -1;
    }else if (x < -PI){
        x += PI;                                            
        signd *= -1;                                         //уменьшаем переменную X
    }

    double result = x, sin_n = x - 1;
    double x_2 = x * x, xk = x;

    long long factorl = 1;
    int counter_fac = 1;

    int k = 1, signd_number = 1;

    while (result - sin_n > 1e-7 || sin_n - result > 1e-7){
        sin_n = result;
        xk *= x_2;

        factorl *=  (counter_fac + 1)*(counter_fac + 2);
        counter_fac += 2;

        if (k % 2 == 1){
            signd_number = -1;
        }
        else signd_number = 1;
        
        result += signd_number*xk/factorl;
        ++k;
    }
    return result*signd;
}


double my_cos(double x){

    int signd_cos = 1;
    if (x < 0)
        x =-x;
    if (x > 2*PI)
        x = reducingArgument(x);
    if(x > 2*PI){                                          //уменьшаем переменную X
        x -= (long long)(x/(2*PI))*2*PI;
    }
    if(x < -2*PI){
        x += (long long)(-x/(2*PI))*2*PI;
    }
    if (x > PI){
        x -= PI;
        signd_cos= -1;
    }else if (x < -PI){
        x += PI;                                            
        signd_cos = -1;                                         //уменьшаем переменную X
    }
    double result_cos = 1, cos_n = 0;
    double x_2 = x * x, xk = 1;

    long long factorl = 1;
    int counter_fac = 0;

    int k = 1, signd_number = 1;

    while (result_cos - cos_n > 1e-7 || cos_n - result_cos > 1e-7){
        cos_n = result_cos;
        xk *= x_2;

        factorl *=  (counter_fac + 1)*(counter_fac + 2);
        counter_fac += 2;

        if (k % 2 == 1){
            signd_number = -1;
        }
        else signd_number = 1;
        
        result_cos += signd_number*xk/factorl;
        ++k;
    }
    return result_cos*signd_cos;
}

long double ln_abs(double x){
    if(x < 0)
        x = -x;
    int j = 0;

    while (x > 2) {
        x /= 2;
        j++;
    }
    while (x < 0.5) {
        x *= 2;
        j--;
    }
    long double res = j * 0.6931471805599453, factor = x - 1;
    short sign = 1;
    for(int i = 1; i <= 80; ++i){
        res += sign*factor/i;
        factor *= x - 1;
        sign *=-1;
    }
    return res;
}

void minF3(double x_value){
    double cos_value = my_cos(x_value);
    double sin_value = my_sin(x_value);
    double ln_value = ln_abs(x_value);
    if (ln_value < sin_value && ln_value < sin_value)
        std::cout << "Минимальное значение при заданном x = "<< x_value << " принимает функция ln|x| = " << ln_value << '\n' << std::endl;
    else if (sin_value < ln_value && sin_value < cos_value)
        std::cout << "Минимальное значение при заданном x = "<< x_value << " принимает функция sin(x) = " << sin_value<< '\n' << std::endl;
    else 
        std::cout << "Минимальное значение при заданном x = "<< x_value << " принимает функция cos(x) = " << cos_value<< '\n' << std::endl;
}

void minF2(double x_value){
    double cos_value = my_cos(x_value);
    double sin_value = my_sin(x_value);
    if (cos_value < sin_value)
        std::cout << "Минимальное значение при заданном x = "<< x_value << " принимает функция cos(x) = " << cos_value << "\n" << std::endl;
    else
        std::cout << "Минимальное значение при заданном x = "<< x_value << " принимает функция sin(x) = " << sin_value << "\n" << std::endl;
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
    std::string strX;
    long double x;
    bool flagStop = false;
    while(true){
        std::cout << "Выполнил Левчишин Иван.\nГруппа-453505" << std::endl;
        std::cout << "Данная программа из величин, определяемых выражениями a = sinx, b = cosx, c = ln|x| при заданном х,\n"
        << "определяет и выводит на экран дисплея минимальное значение." << std::endl;
        
        while(true){
            std::cout << "Введите число x для нахождения минимального из выражений a = sinx, b = cosx, c = ln|x|: ";
            std::getline(std::cin, strX);
            delSpace(strX);
            if (isLDRight(commaReplacement(strX))){
                x = std::stold(commaReplacement(strX));
                break;
            }
            else{
                std::cout << "Введено некорректное значение или значение превышающее предел. Пожалуйста повторите попытку ввода\n" << std::endl;
                continue;
            }

        }

        
        if (x < -2 || x > 2){
            minF2(x);
        }else
            minF3(x);
        
        
        if (stopProgram(flagStop))
                break;
    }
    return 0;
}