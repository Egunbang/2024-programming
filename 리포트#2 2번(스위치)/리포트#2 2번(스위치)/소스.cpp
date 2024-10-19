#include <stdio.h>

int main(void) 
{
    int num1, num2;

    // 사용자로부터 두 개의 정수 입력받기
    printf("첫 번째 정수를 입력하시오: ");
    scanf_s("%d", &num1);
    printf("두 번째 정수를 입력하시오: ");
    scanf_s("%d", &num2);

    // 배수 관계 판별
    switch (num2 == 0 ? -1 : num1 % num2) 
    {
    case 0:
        printf("%d는 %d의 배수입니다.\n", num1, num2);
        break;
    
    case -1:
        printf("0으로 나눌 수 없습니다.\n");
        break;
    
    default:
        printf("%d는 %d의 배수가 아닙니다.\n", num1, num2);
        break;
    }

    return 0;
}
