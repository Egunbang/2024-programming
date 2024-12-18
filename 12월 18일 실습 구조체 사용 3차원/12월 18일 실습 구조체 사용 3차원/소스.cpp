#include <stdio.h>
#include <math.h>

// 3���� ���� ���� ����ü ����
typedef struct
{
    double x;
    double y;
    double z;
} Point;

// �� �� ������ ��Ŭ���� �Ÿ� ��� �Լ�
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

    // ����ڷκ��� �� �� �Է�
    printf("ù ��° ���� ��ǥ�� �Է��ϼ��� (x y z): ");
    scanf_s("%lf %lf %lf", &point1.x, &point1.y, &point1.z);

    printf("�� ��° ���� ��ǥ�� �Է��ϼ��� (x y z): ");
    scanf_s("%lf %lf %lf", &point2.x, &point2.y, &point2.z);

    // �Ÿ� ���
    double distance = CalculDis(&point1, &point2);

    // ��� ���
    printf("�� �� ������ �Ÿ���: %.2f\n", distance);

    return 0;
}
