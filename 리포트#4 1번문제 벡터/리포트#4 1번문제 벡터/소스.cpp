#include <stdio.h>  // 표준 입출력 라이브러리 포함

// 두 벡터의 외적을 계산하는 함수
void crossProduct(int* x1, int* y1, int* z1, int* x2, int* y2, int* z2, int* cross_x, int* cross_y, int* cross_z) 
{
    *cross_x = (*y1) * (*z2) - (*z1) * (*y2);  // x 성분 계산
    *cross_y = (*z1) * (*x2) - (*x1) * (*z2);  // y 성분 계산
    *cross_z = (*x1) * (*y2) - (*y1) * (*x2);  // z 성분 계산
}

// 두 벡터의 내적을 계산하는 함수
int dotProduct(int* x1, int* y1, int* z1, int* x2, int* y2, int* z2) 
{
    return (*x1) * (*x2) + (*y1) * (*y2) + (*z1) * (*z2);  // 내적 계산
}

int main(void) 
{
    int x1, y1, z1;  // 벡터 1의 성분
    int x2, y2, z2;  // 벡터 2의 성분
    int cross_x, cross_y, cross_z;  // 외적 결과 성분
    int dot;  // 내적 결과

    // 벡터 1 입력
    printf("벡터 1의 성분 (x, y, z)을 입력하세요: ");
    scanf_s("%d %d %d", &x1, &y1, &z1);

    // 벡터 2 입력
    printf("벡터 2의 성분 (x, y, z)을 입력하세요: ");
    scanf_s("%d %d %d", &x2, &y2, &z2);

    // 외적 계산
    crossProduct(&x1, &y1, &z1, &x2, &y2, &z2, &cross_x, &cross_y, &cross_z);

    // 내적 계산
    dot = dotProduct(&x1, &y1, &z1, &x2, &y2, &z2);

    // 결과 출력
    printf("외적 결과: (%d, %d, %d)\n", cross_x, cross_y, cross_z);
    printf("내적 결과: %d\n", dot);

    return 0;  // 프로그램 종료
}
