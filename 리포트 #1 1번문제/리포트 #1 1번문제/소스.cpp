#include <stdio.h>

int main(void) 
{
    double deg;

    // ���� �Է�
    printf("������ �Է��Ͻÿ� (0 �̻�): ");
    scanf_s("%lf", &deg);

    // 0 ~ 360 ������ -180 ~ +180 ������ ��ȯ�Ѵ�
    deg = deg - 360 * ((int)(deg / 360)); // 0 ~ 360 ������ �����Ѵ�
    deg = (deg > 180) ? (deg - 360) : deg; // 180 �ʰ� �� -360�� �����ش�

    // ��� ���
    printf("��ȯ�� �ڼ���: %.2f ��\n", deg);

    return 0;
}
