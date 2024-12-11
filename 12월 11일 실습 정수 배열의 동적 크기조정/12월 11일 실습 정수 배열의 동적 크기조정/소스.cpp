#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �迭�� ����, ���, �л�, ǥ�������� ����ϴ� �Լ�
void calculateStatistics(int* arr, int size, int* sum, double* mean, double* variance, double* std_dev) 
{
    *sum = 0;
    double variance_sum = 0.0;

    // ���� ���
    for (int i = 0; i < size; i++) 
    {
        *sum += *(arr + i);
    }

    // ��� ���
    *mean = (double)(*sum) / size;

    // �л� ���
    for (int i = 0; i < size; i++) 
    {
        variance_sum += pow(*(arr + i) - *mean, 2);
    }

    *variance = variance_sum / size;
    *std_dev = sqrt(*variance);
}

int main(void)
{
    int initial_size, additional_size;
    int* arr = NULL;
    int sum;
    double mean, variance, std_dev;

    // �ʱ� �迭 ũ�� �Է¹ޱ�
    printf("�ʱ� �迭�� ũ�⸦ �Է��ϼ���: ");
    scanf_s("%d", &initial_size);

    // �迭 ���� �Ҵ�
    arr = (int*)malloc(initial_size * sizeof(int));
    if (arr == NULL) {
        printf("�޸� �Ҵ� ����");
        return 1;
    }

    // �ʱ� �迭 �� �Է¹ޱ�
    printf("�ʱ� �迭�� ���� �Է��ϼ���:");
    for (int i = 0; i < initial_size; i++) 
    {
        scanf_s("%d", arr + i);
    }

    // �ʱ� �迭�� ����, ���, �л�, ǥ������ ���
    calculateStatistics(arr, initial_size, &sum, &mean, &variance, &std_dev);
    printf("�ʱ� �迭 - ����: %d, ���: %.2f, �л�: %.2f, ǥ������: %.2f\n", sum, mean, variance, std_dev);

    // �߰� �迭 ũ�� �Է¹ޱ�
    printf("�߰��� �迭�� ũ�⸦ �Է��ϼ���: ");
    scanf_s("%d", &additional_size);

    // �迭 ũ�� ���Ҵ�
    arr = (int*)realloc(arr, (initial_size + additional_size) * sizeof(int));
    if (arr == NULL)
    {
        printf("�޸� ���Ҵ� ����\n");
        return 1;
    }

    // �߰� �迭 �� �Է¹ޱ�
    printf("�߰� �迭�� ���� �Է��ϼ���:");
    for (int i = initial_size; i < initial_size + additional_size; i++) 
    {
        scanf_s("%d", arr + i);
    }

    // �߰��� �迭�� ����, ���, �л�, ǥ������ ���
    calculateStatistics(arr, initial_size + additional_size, &sum, &mean, &variance, &std_dev);
    printf("�߰��� �迭 - ����: %d, ���: %.2f, �л�: %.2f, ǥ������: %.2f", sum, mean, variance, std_dev);

    // �޸� ����
    free(arr);

    return 0;
}
