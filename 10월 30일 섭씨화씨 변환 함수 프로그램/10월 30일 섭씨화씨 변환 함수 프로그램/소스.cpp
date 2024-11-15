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

    printf("�µ��� �Է��Ͻÿ�(C or F�����Է�) :");
    scanf_s("%lf %c", &temp, &degree);

    if (degree == 'C' || degree == 'c')
    {
        double fah = ctof(temp);
        printf("%.2f C�� %.2f F�̴�\n", temp, fah);
    }
    else if (degree == 'F' || degree =='f') 
    {
        double celsius = ftoc(temp);
        printf("%.2f F�� %.2f C�̴�", temp, celsius);
    }
    else 
    {
        printf("�߸��ȴ����̴�, C �Ǵ� F������ ����Ͻÿ�");
    } 
    return 0;
}