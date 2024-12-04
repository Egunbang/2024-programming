#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 배열 크기 정의하기
#define ARRAY_SIZE 10

// 값의 범위 정의하기
#define MIN -100.0
#define MAX 100.0

// 랜덤하게 배열을 생성하는 함수 만들기
void GenerateArray(float arr[], int size) 
{
    srand(time(0)); // 난수 생성을 위한 시드 초기화하기
    for (int i = 0; i < size; i++) 
    {
        arr[i] = MIN + (rand() / (float)RAND_MAX) * (MAX - MIN);
    }
}

// 배열을 역순으로 변경하는 함수 만들기
void CalcInverseArray(float arr[], int size) 
{
    for (int i = 0; i < size / 2; i++)
    {
        float temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

// 배열을 출력하는 함수 만들기
void PrintArray(float arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%.3lf ", arr[i]);
    }
    printf("\n");
}

// 메인 함수
int main(void) 
{
    float arr[ARRAY_SIZE];

    GenerateArray(arr, ARRAY_SIZE);
    printf("랜덤 배열: ");
    PrintArray(arr, ARRAY_SIZE);

    CalcInverseArray(arr, ARRAY_SIZE);
    printf("역순 배열: ");
    PrintArray(arr, ARRAY_SIZE);

    return 0;
}
