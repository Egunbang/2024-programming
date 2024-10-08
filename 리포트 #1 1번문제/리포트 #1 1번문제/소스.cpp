#include <stdio.h>

int main(void) 
{
    double deg;

    // 각도 입력
    printf("각도를 입력하시오 (0 이상): ");
    scanf_s("%lf", &deg);

    // 0 ~ 360 범위를 -180 ~ +180 범위로 변환한다
    deg = deg - 360 * ((int)(deg / 360)); // 0 ~ 360 범위로 조정한다
    deg = (deg > 180) ? (deg - 360) : deg; // 180 초과 시 -360를 더해준다

    // 결과 출력
    printf("변환된 자세각: %.2f 도\n", deg);

    return 0;
}
