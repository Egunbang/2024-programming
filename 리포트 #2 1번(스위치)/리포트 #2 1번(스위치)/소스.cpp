#include <stdio.h>

int main(void) 
{
    int number;

    // 정수 입력받기
    printf("정수를 입력하시오: ");
    scanf_s("%d", &number);

    // 짝수인지 홀수인지 판별하기
    switch (number % 2)   // 2로 나누었을 때 0이면 첫번째 실행문, 1이면 2번째 실행문
    {
    case 0:
        printf("%d는 짝수입니다.\n", number);
        break;
    
    case 1:
        printf("%d는 홀수입니다.\n", number);
        break;
    }

    return 0;
}   
