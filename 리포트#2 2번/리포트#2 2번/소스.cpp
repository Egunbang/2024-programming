#include <stdio.h>

int main(void) 
{
    int num1, num2;

    // 두 개의 정수 입력받기
    printf("첫 번째 정수를 입력하시오: ");
    scanf_s("%d", &num1);
    printf("두 번째 정수를 입력하시오: ");
    scanf_s("%d", &num2);

    // 배수 관계 판별하기
    if (num2 != 0 && num1 % num2 == 0)// &&은 두 조건 모두 참이어야 발동된다. 
                                      //첫번째 조건문으로 0인지 파악하여 계산 오류를 방지한다
                                      //두번재 조건문으로 num1 X num2을 했을 때 나머지가 0이면 num1,이 num2의 배수라는 뜻이다.
    {
        printf("%d는 %d의 배수입니다.\n", num1, num2);
    }
    else {
        printf("%d는 %d의 배수가 아닙니다.\n", num1, num2);
    }

    return 0;
}
