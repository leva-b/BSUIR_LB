#include <iostream>

const double PI = 3.14159265358979323846;

double square_root(double number){

    if (number == 0) 
        return 0;
    
    double square = number, xn;                  //задание начального приближения
    if (number > 1)
        xn = number / 2;
    else xn = 0.5;

    while (square - xn > 1e-7 || xn - square > 1e-7){
        xn = square;
        square = (xn + number/xn)/2; 
    }

    return square;
}

double power(double x, int degree){

    double result = 1;

    for(int i = 1; i <=degree; i++){
        result *= x;
    }

    return result;
}

long long factorial(int x){
    long long result_fact = 1;

    for(int i = 2; i <= x; i++){
        result_fact *= i;
    }
    
    return result_fact;
}

double arcsin(double x){
    double res = x;
    for (int k = 1; k <= 60; k++){
        res += factorial(2*k)*power(x,2*k + 1)/power(4,k)/power(factorial(k),2)/(2*k+1); 
    }
    return res;
}

double arccos(double cos_value){

    if (cos_value >= 0.91)
        return square_root(2*(1-cos_value));

    else if(cos_value <= -0.91)
        return PI - square_root(2*(1 + cos_value));

    return PI/2 - arcsin(cos_value);
}

double my_sin(double x){

    int signd = 1;
    if (x > 2*PI){                                          //уменьшаем переменную X
        x -= int(x/(2*PI))*2*PI;
    }else if(x < -2*PI){
        x -= int(x/(2*PI))*2*PI;
    }
    if (x > PI){
        x -= PI;
        signd = -1;
    }else if (x < -PI){
        x += PI;                                            
        signd = -1;                                         //уменьшаем переменную X
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

double absolute(double number){
    if (number < 0)
        return -number;
    else 
        return number;
}

int main(){

    double x1, y1, x2, y2, x3, y3;
    double a, b, c, ma, mb, mc, ha, hb, hc;
    double la, lb, lc;
    double rad_a, rad_b, rad_c, grad_a, grad_b, grad_c;
    double R, r, CR, Cr, SR, Sr;
    double S1, S2, S3, S4, P, p;
    std::cout << "Введите координаты вершин треугольника: ";
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    a = square_root((x1 - x2)*(x1 - x2)+(y1 - y2)*(y1 - y2));
    b = square_root((x1 - x3)*(x1 - x3)+(y1 - y3)*(y1 - y3));
    c = square_root((x2 - x3)*(x2 - x3)+(y2 - y3)*(y2 - y3));
    std::cout << "Длины сторон треугольника равны:\na = " << a << "\nb = " << b << "\nc = " << c; 

    S1 = 0.5 * absolute(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    P = a + b + c;
    p = P/2;

    ha = 2 * S1 / a;
    hb = 2 * S1 / b;
    hc = 2 * S1 / c;
    std::cout << "\nДлины высот треугольника равны:\nha = " << ha << "\nhb = " << hb << "\nhc = " << hc;

    ma = 0.5 * square_root(2*c*c + 2*b*b - a*a);
    mb = 0.5 * square_root(2*c*c + 2*a*a - b*b);
    mc = 0.5 * square_root(2*a*a + 2*b*b - c*c);
    std::cout << "\nДлины медиан треугольника равны:\nma = " << ma << "\nmb = " << mb << "\nmc = " << mc;

    la = 2 * square_root(b*c*p * (p - a)) / (b + c);
    lb = 2 * square_root(a*c*p * (p - b)) / (a + c);
    lc = 2 * square_root(a*b*p * (p - c)) / (a + b); 
    std::cout << "\nДлины биссектрис треугольника равны:\nla = " << la << "\nlb = " << lb << "\nlc = " << lc;

    rad_a = arccos((b*b + c*c - a*a)/(2 * b * c));
    rad_b = arccos((a*a + c*c - b*b)/(2 * a * c));
    rad_c = arccos((b*b + a*a - c*c)/(2 * b * a));
    std::cout << "\nРадианные меры углов треугольника равны:\nrad_a = " << rad_a << "\nrad_b = " << rad_b << "\nrad_c = " << rad_c;
    grad_a = rad_a * 180 / PI;
    grad_b = rad_b * 180 / PI;
    grad_c = rad_c * 180 / PI;
    std::cout << "\nГрадусные меры углов треугольника равны:\ngrad_a = " << grad_a << "\ngrad_b = " << grad_b << "\ngrad_c = " << grad_c;


    R = a*b*c / 4/S1;
    r = S1 / p;
    std::cout << "\nРадиус описанной и вписанной окружностей:\nR = " << R << "\nr = " << r;
    SR = PI * R * R;
    Sr = PI * r * r;
    CR = 2 * PI * R;
    Cr = 2 * PI * r;
    std::cout << "\nПлощадь и длина каждой окружности соответственно равны:\nSR = " << SR << "\nSr = " << Sr << "\nCR = " << CR << "\nCr = " << Cr;

    S2 = square_root(p * (p-a) * (p-b)* (p-c));
    S3 = p * r;
    S4 = 0.5 * a * b * my_sin(rad_c);
    std::cout << "\nПериметр треугольника равен:\nP = " << P;
    std::cout << "\nПлощадь треугольника равна:\nS1 = " << S1 << "\nS2 = " << S2 << "\nS3 = " << S3 << "\nS4 = " << S4; 
    return 0;
}