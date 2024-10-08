#include <stdio.h>

float range(float angle) {
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
    printf("각도를 입력하세요 (0~360도 이상): ");
    scanf_s("%f", &angle);
    float convertedAngle = range(angle);
    printf("변환된 각도: %f도\n", convertedAngle);
    return 0;
}
