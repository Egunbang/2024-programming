#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// ������ �Ǽ� �迭 �����ϱ�
void GenerateArray(float array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        array[i] = ((float)rand() / RAND_MAX) * 200.0f - 100.0f; // -100.0 ~ +100.0 ������ �� �����ϱ�
    }
}

// �迭 ����ϱ�
void PrintArray(float array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%6.2f ", array[i]);
    }
    printf("\n");
}

// �迭 ���� �Լ� (�ɼǿ� ���� ��������/�������� ����) �̰� �ǳפ�
void CalcSortArray(float array[], int size, int ascending) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((ascending && array[j] > array[j + 1]) || (!ascending && array[j] < array[j + 1]))
            {
                // �� ��ȯ�ϱ�
                float temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    float array[SIZE];

    // ���� �õ� �����ϱ�
    srand((unsigned int)time(NULL));

    // �迭 �����ϱ�
    GenerateArray(array, SIZE);

    // ������ �迭 ����ϱ�
    printf("���� ������ �迭:\n");
    PrintArray(array, SIZE);

    // �迭 ���� (��������)
    CalcSortArray(array, SIZE, 1);
    printf("\n�������� ���ĵ� �迭:\n");
    PrintArray(array, SIZE);
    
    // �迭 ������ϱ�
    GenerateArray(array, SIZE);

    // �迭 ���� (��������)
    CalcSortArray(array, SIZE, 0);
    printf("\n�������� ���ĵ� �迭:\n");
    PrintArray(array, SIZE);

    return 0;
}
