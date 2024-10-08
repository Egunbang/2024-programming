#include <stdio.h>

float convertToRange(float angle) {
    while (angle > 180) {
        angle -= 360;
    }
    while (angle <= -180) {
        angle += 360;
    }
    return angle;
}

int main() {
    float angle;
    printf("������ �Է��ϼ��� (0~360�� �̻� ����): ");
    scanf_s("%f", &angle);
    float convertedAngle = convertToRange(angle);
    printf("��ȯ�� ����: %f��\n", convertedAngle);
    return 0;
}
