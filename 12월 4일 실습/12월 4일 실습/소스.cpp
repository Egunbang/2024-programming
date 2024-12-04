#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

// 랜덤한 실수 배열 생성하기
void GenerateArray(float array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        array[i] = ((float)rand() / RAND_MAX) * 200.0f - 100.0f; // -100.0 ~ +100.0 범위의 값 생성하기
    }
}

// 배열 출력하기
void PrintArray(float array[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%6.2f ", array[i]);
    }
    printf("\n");
}

// 배열 정렬 함수 (옵션에 따라 오름차순/내림차순 선택) 이게 되네ㅐ
void CalcSortArray(float array[], int size, int ascending) 
{
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((ascending && array[j] > array[j + 1]) || (!ascending && array[j] < array[j + 1]))
            {
                // 값 교환하기
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

    // 랜덤 시드 설정하기
    srand((unsigned int)time(NULL));

    // 배열 생성하기
    GenerateArray(array, SIZE);

    // 생성된 배열 출력하기
    printf("랜덤 생성된 배열:\n");
    PrintArray(array, SIZE);

    // 배열 정렬 (오름차순)
    CalcSortArray(array, SIZE, 1);
    printf("\n오름차순 정렬된 배열:\n");
    PrintArray(array, SIZE);
    
    // 배열 재생성하기
    GenerateArray(array, SIZE);

    // 배열 정렬 (내림차순)
    CalcSortArray(array, SIZE, 0);
    printf("\n내림차순 정렬된 배열:\n");
    PrintArray(array, SIZE);

    return 0;
}
