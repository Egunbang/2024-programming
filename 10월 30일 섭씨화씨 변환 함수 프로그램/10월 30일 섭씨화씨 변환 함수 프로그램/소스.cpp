#include <stdio.h>

double ctof(double celsius) 
{
    return (celsius * 9.0 / 5.0) + 32;
}
double ftoc(double fah) 
{
    return(fah - 32) * 5.0 / 9.0;
}


int main(void)
{
    double temp;
    char degree;

    printf("온도를 입력하시오(C or F단위입력) :");
    scanf_s("%lf %c", &temp, &degree);

    if (degree == 'C' || degree == 'c')
    {
        double fah = ctof(temp);
        printf("%.2f C는 %.2f F이다\n", temp, fah);
    }
    else if (degree == 'F' || degree =='f') 
    {
        double celsius = ftoc(temp);
        printf("%.2f F는 %.2f C이다", temp, celsius);
    }
    else 
    {
        printf("잘못된단위이다, C 또는 F단위를 사용하시오");
    } 
    return 0;
}