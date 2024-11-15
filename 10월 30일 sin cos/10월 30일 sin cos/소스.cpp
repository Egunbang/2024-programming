#include <stdio.h>

// 각도를 라디안으로 변환하는 함수
double degtorad(double degree) 
{
    return degree * (3.14159265358979323846 / 180.0);
}

// sin 값을 계산하는 함수
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

// cos 값을 계산하는 함수
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

    // 사용자로부터 각도 입력받기
    printf("각도를 입력하시오 (0-180): ");
    scanf_s("%lf", &degree);

    // 입력된 각도의 sin, cos 값을 계산하고 출력
    double sin = calsin(degree);
    double cos = calcos(degree);
    printf("각도: %.2f, sin: %.4f, cos: %.4f\n", degree, sin, cos);

    return 0;
}
