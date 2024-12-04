#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define UNUSED 0 // ������ ���� �ε����� ��Ÿ���� ���̴�

// ������ ���� �迭 �����ϱ�
void GenerateArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 101; // 0 ~ 100 ������ �� �����ϱ�
    }
}

// �迭 ��� �ϱ�
void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == UNUSED) 
        {
            printf("X ");    // X�� �Ǵ� ������ ��Ÿ���� ��ȣ ����ϱ�
        }
        else
        {
            printf("%3d ", array[i]);
        }
    }
    printf("\n");
}

// ¦���� Ȧ���� �и��Ͽ� �����ϴ� �Լ� �����
void CalcEvenOddArray(int inputArray[], int size, int evenArray[], int oddArray[])
{
    int evenIndex = 0, oddIndex = 0;

    // ¦���� Ȧ�� �迭 �ʱ�ȭ�ϱ�
    for (int i = 0; i < size; i++)
    {
        evenArray[i] = UNUSED;
        oddArray[i] = UNUSED;
    }

    for (int i = 0; i < size; i++)
    {
        if (inputArray[i] % 2 == 0)
        {
            evenArray[evenIndex++] = inputArray[i];
        }
        else 
        {
            oddArray[oddIndex++] = inputArray[i];
        }
    }
}

int main()
{
    int inputArray[SIZE];
    int evenArray[SIZE];
    int oddArray[SIZE];

    // ���� �õ� �����ϱ�
    srand((unsigned int)time(NULL));

    // �迭 �����ϱ�
    GenerateArray(inputArray, SIZE);

    // ������ �迭 ����ϱ�
    printf("���� ���� �迭:\n");
    PrintArray(inputArray, SIZE);

    // ¦���� Ȧ�� �и��ϱ�
    CalcEvenOddArray(inputArray, SIZE, evenArray, oddArray);

    // ¦�� �迭 ����ϱ�
    printf("\n¦�� �迭:\n");
    PrintArray(evenArray, SIZE);

    // Ȧ�� �迭 ����ϱ�
    printf("\nȦ�� �迭:\n");
    PrintArray(oddArray, SIZE);

    return 0;
}
