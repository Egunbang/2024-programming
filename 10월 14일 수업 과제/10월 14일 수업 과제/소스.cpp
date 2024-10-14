#include <stdio.h>

int main(void) 
{
    char giho; 
    int a, b; 

    
    printf("사칙연산 입력(정수): ");
    scanf_s("%d %c %d", &a, &giho, 1, &b);

    
    if (giho == '+') 
    {
        printf("%d %c %d = %d\n", a, giho, b, a + b);
    }
    else if (giho == '-') 
    {
        printf("%d %c %d = %d\n", a, giho, b, a - b);
    }
    else if (giho == '*') 
    {
        printf("%d %c %d = %d\n", a, giho, b, a * b);
    }
    else if (giho == '/') 
    {
        if (b != 0) 
        {
            printf("%d %c %d = %d\n", a, giho, b, a / b);
        }
        else 
        {
            printf("0\n");
        }
    }
    

    return 0;
}
