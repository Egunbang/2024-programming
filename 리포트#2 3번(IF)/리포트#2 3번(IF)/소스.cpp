#include <stdio.h>

int main(void) 
{
    float score;

    // 실수 입력받기
    printf("점수를 입력하시오 (0.0 ~ 100.0): ");
    scanf_s("%f", &score);

    // 점수에 따라 학점 출력
    if (score >= 90.0) 
    {
        printf("학점: A\n");
    }
    else if (score >= 80.0) 
    {
        printf("학점: B\n");
    }
    else if (score >= 70.0) 
    {
        printf("학점: C\n");
    }
    else if (score >= 60.0) 
    {
        printf("학점: D\n");
    }
    else 
    {
        printf("학점: F\n");
    }

    return 0;
}
