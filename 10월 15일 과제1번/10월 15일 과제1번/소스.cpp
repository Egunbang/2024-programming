#include <stdio.h>

int main(void)
{
    char giho;
    int a, b;


    printf("��Ģ���� �Է�(����): ");
    scanf_s("%d %c %d", &a, &giho, 1, &b);

    switch (giho)
    {
     case '+':
        printf("%d %c %d = %d\n", a, giho, b, a + b);
        break;

     case '-':
         printf("%d %c %d = %d\n", a, giho, b, a - b);
         break;
     
     case '*':
        printf("%d %c %d = %d\n", a, giho, b, a * b);
        break;

     case'/':
         printf("%d %c %d = %d\n", a, giho, b, a / b);
         break;
    }
   
    return 0;
}