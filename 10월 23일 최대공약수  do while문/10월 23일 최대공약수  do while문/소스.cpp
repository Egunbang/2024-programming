#include <stdio.h>

int main(void)
{
    int num1, num2, maxnum, minnum;

    printf("�� ���ڸ� �Է��Ͻÿ�");
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


    printf("�ִ����� :%d\n", maxnum);
    printf("�ּҰ���� :%d\n", minnum);


    return 0;
}