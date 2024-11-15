#include <stdio.h>

// ������ �������� ��ȯ�ϴ� �Լ�
double degtorad(double degree) 
{
    return degree * (3.14159265358979323846 / 180.0);
}

// sin ���� ����ϴ� �Լ�
double calsin(double degree) 
{
    double radian = degtorad(degree);
    double result = radian;
    double term = radian;
    int n;
    for (n = 1; n < 10; n++) 
    {
        term *= -radian * radian / ((2 * n) * (2 * n + 1));
        result += term;
    }
  return result;
}

// cos ���� ����ϴ� �Լ�
double calcos(double degree) 
{
    double radian = degtorad(degree);
    double result = 1.0;
    double term = 1.0;
    int n;

    for (n = 1; n < 10; n++) 
    {
        term *= -radian * radian / ((2 * n - 1) * (2 * n));
        result += term;
    }  
    return result;
}

int main(void) 
{
    double degree;

    // ����ڷκ��� ���� �Է¹ޱ�
    printf("������ �Է��Ͻÿ� (0-180): ");
    scanf_s("%lf", &degree);

    // �Էµ� ������ sin, cos ���� ����ϰ� ���
    double sin = calsin(degree);
    double cos = calcos(degree);
    printf("����: %.2f, sin: %.4f, cos: %.4f\n", degree, sin, cos);

    return 0;
}
