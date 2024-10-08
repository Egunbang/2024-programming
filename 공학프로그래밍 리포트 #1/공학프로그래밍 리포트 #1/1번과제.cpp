#include <stdio.h>

float convertToRange(float angle) {
    if (angle >= 0 && angle <= 360) {
        while (angle > 180) angle -= 360;
        while (angle < -180) angle += 360;
    }
    else {
        printf("0 ~ 360도 범위 내에서 입력해주세요.\n");
        return -1;  // 유효하지 않은 값 반환
    }
    return angle;
}

int main() {
    float angle;
    printf("각도를 입력하세요 (0 ~ 360도): ");
    int result = scanf("%f", &angle);

    if (result == 1) {
        float convertedAngle = convertToRange(angle);
        if (convertedAngle != -1) {
            printf("변환된 각도: %f도\n", convertedAngle);
        }
    }
    else {
        printf("올바른 실수 값을 입력해주세요.\n");
    }

    return 0;
}