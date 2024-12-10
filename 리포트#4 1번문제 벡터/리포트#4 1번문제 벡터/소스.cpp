#include <stdio.h>  // ǥ�� ����� ���̺귯�� ����

// �� ������ ������ ����ϴ� �Լ�
void crossProduct(int* x1, int* y1, int* z1, int* x2, int* y2, int* z2, int* cross_x, int* cross_y, int* cross_z) 
{
    *cross_x = (*y1) * (*z2) - (*z1) * (*y2);  // x ���� ���
    *cross_y = (*z1) * (*x2) - (*x1) * (*z2);  // y ���� ���
    *cross_z = (*x1) * (*y2) - (*y1) * (*x2);  // z ���� ���
}

// �� ������ ������ ����ϴ� �Լ�
int dotProduct(int* x1, int* y1, int* z1, int* x2, int* y2, int* z2) 
{
    return (*x1) * (*x2) + (*y1) * (*y2) + (*z1) * (*z2);  // ���� ���
}

int main(void) 
{
    int x1, y1, z1;  // ���� 1�� ����
    int x2, y2, z2;  // ���� 2�� ����
    int cross_x, cross_y, cross_z;  // ���� ��� ����
    int dot;  // ���� ���

    // ���� 1 �Է�
    printf("���� 1�� ���� (x, y, z)�� �Է��ϼ���: ");
    scanf_s("%d %d %d", &x1, &y1, &z1);

    // ���� 2 �Է�
    printf("���� 2�� ���� (x, y, z)�� �Է��ϼ���: ");
    scanf_s("%d %d %d", &x2, &y2, &z2);

    // ���� ���
    crossProduct(&x1, &y1, &z1, &x2, &y2, &z2, &cross_x, &cross_y, &cross_z);

    // ���� ���
    dot = dotProduct(&x1, &y1, &z1, &x2, &y2, &z2);

    // ��� ���
    printf("���� ���: (%d, %d, %d)\n", cross_x, cross_y, cross_z);
    printf("���� ���: %d\n", dot);

    return 0;  // ���α׷� ����
}
