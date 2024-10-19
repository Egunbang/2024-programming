#include <stdio.h>

int main(void) 
{
    double score; //실수로 표현

    // 실수 입력받기
    printf("점수를 입력하시오 (0.0 ~ 100.0): ");
    scanf_s("%lf", &score);

    // 점수를 정수로 변환하여 스위치문 사용
    switch ((int)score / 10) 
    {
     case 10:
     case 9:
        printf("학점: A\n"); //90점 이상은 A학점
        break;
    
     case 8:
        printf("학점: B\n"); //80점 이상은 B학점
        break;
    
     case 7:
        printf("학점: C\n"); //70점 이상은 C학점
        break;
    
     case 6:
        printf("학점: D\n"); //60점 이상은 D학점
        break;
    
     default:
        printf("학점: F\n");
        break;//60미만은 F학점
    }

    return 0;
}
