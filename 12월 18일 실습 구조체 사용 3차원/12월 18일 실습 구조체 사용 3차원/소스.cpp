#include <stdio.h>
#include <math.h>

// 3차원 점에 대한 구조체 선언
typedef struct
{
    double x;
    double y;
    double z;
} Point;

// 두 점 사이의 유클리드 거리 계산 함수
double CalculDis(Point* p1, Point* p2) 
{
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main(void) 
{
    Point point1, point2;

    // 사용자로부터 두 점 입력
    printf("첫 번째 점의 좌표를 입력하세요 (x y z): ");
    scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z);

    printf("두 번째 점의 좌표를 입력하세요 (x y z): ");
    scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z);

    // 거리 계산
    double distance = CalculDis(&point1, &point2);

    // 결과 출력
    printf("두 점 사이의 거리는: %.2f\n", distance);

    return 0;
}
