#include <stdio.h>

float convertToRange(float angle) {
    if (angle >= 0 && angle <= 360) {
        while (angle > 180) angle -= 360;
        while (angle < -180) angle += 360;
    }
    else {
        printf("0 ~ 360�� ���� ������ �Է����ּ���.\n");
        return -1;  // ��ȿ���� ���� �� ��ȯ
    }
    return angle;
}

int main() {
    float angle;
    printf("������ �Է��ϼ��� (0 ~ 360��): ");
    int result = scanf("%f", &angle);

    if (result == 1) {
        float convertedAngle = convertToRange(angle);
        if (convertedAngle != -1) {
            printf("��ȯ�� ����: %f��\n", convertedAngle);
        }
    }
    else {
        printf("�ùٸ� �Ǽ� ���� �Է����ּ���.\n");
    }

    return 0;
}