#include <stdio.h>

int main(void) 
{
    float score;

    // �Ǽ� �Է¹ޱ�
    printf("������ �Է��Ͻÿ� (0.0 ~ 100.0): ");
    scanf_s("%f", &score);

    // ������ ���� ���� ���
    if (score >= 90.0) 
    {
        printf("����: A\n");
    }
    else if (score >= 80.0) 
    {
        printf("����: B\n");
    }
    else if (score >= 70.0) 
    {
        printf("����: C\n");
    }
    else if (score >= 60.0) 
    {
        printf("����: D\n");
    }
    else 
    {
        printf("����: F\n");
    }

    return 0;
}
