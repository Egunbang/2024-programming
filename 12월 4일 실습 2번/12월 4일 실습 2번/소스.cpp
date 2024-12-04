#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �迭 ũ�� �����ϱ�
#define ARRAY_SIZE 10

// ���� ���� �����ϱ�
#define MIN -100.0
#define MAX 100.0

// �����ϰ� �迭�� �����ϴ� �Լ� �����
void GenerateArray(float arr[], int size) 
{
    srand(time(0)); // ���� ������ ���� �õ� �ʱ�ȭ�ϱ�
    for (int i = 0; i < size; i++) 
    {
        arr[i] = MIN + (rand() / (float)RAND_MAX) * (MAX - MIN);
    }
}

// �迭�� �������� �����ϴ� �Լ� �����
void CalcInverseArray(float arr[], int size) 
{
    for (int i = 0; i < size / 2; i++)
    {
        float temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// �迭�� ����ϴ� �Լ� �����
void PrintArray(float arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%.3lf ", arr[i]);
    }
    printf("\n");
}

// ���� �Լ�
int main(void) 
{
    float arr[ARRAY_SIZE];

    GenerateArray(arr, ARRAY_SIZE);
    printf("���� �迭: ");
    PrintArray(arr, ARRAY_SIZE);

    CalcInverseArray(arr, ARRAY_SIZE);
    printf("���� �迭: ");
    PrintArray(arr, ARRAY_SIZE);

    return 0;
}
