#include <stdio.h>

int main(void)
{
    int num1, num2, maxnum, minnum;

    printf("두 숫자를 입력하시오");
    scanf_s("%d %d", &num1, &num2);

    int a = num1, b = num2;
    do
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    } while (a != b);
    maxnum = a;


    minnum = (num1 * num2) / maxnum;


    printf("최대공약수 :%d\n", maxnum);
    printf("최소공배수 :%d\n", minnum);


    return 0;
}