#include <stdio.h>

int main(void) 
{
    int number;

    // 정수 입력받기
    printf("정수를 입력하시오: ");
    scanf_s("%d", &number);

    // 짝수인지 홀수인지 판별하기
    if (number %2 == 0)  //2로 나누었을 때 0이면 첫번째 실행문, 0이 아니면 두번째 실행문
    {
        printf("%d은 짝수이다.\n", number);
    }
    else 
    {
        printf("%d은 홀수이다.\n", number);
    }

    return 0;
}
