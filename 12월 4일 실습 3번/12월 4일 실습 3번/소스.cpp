#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define UNUSED 0 // 사용되지 않은 인덱스를 나타내는 값이다

// 랜덤한 정수 배열 생성하기
void GenerateArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 101; // 0 ~ 100 범위의 값 생성하기
    }
}

// 배열 출력 하기
void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == UNUSED) 
        {
            printf("X ");    // X나 또는 없음을 나타내는 기호 사용하기
        }
        else
        {
            printf("%3d ", array[i]);
        }
    }
    printf("\n");
}

// 짝수와 홀수를 분리하여 저장하는 함수 만들기
void CalcEvenOddArray(int inputArray[], int size, int evenArray[], int oddArray[])
{
    int evenIndex = 0, oddIndex = 0;

    // 짝수와 홀수 배열 초기화하기
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

    // 랜덤 시드 설정하기
    srand((unsigned int)time(NULL));

    // 배열 생성하기
    GenerateArray(inputArray, SIZE);

    // 생성된 배열 출력하기
    printf("랜덤 생성 배열:\n");
    PrintArray(inputArray, SIZE);

    // 짝수와 홀수 분리하기
    CalcEvenOddArray(inputArray, SIZE, evenArray, oddArray);

    // 짝수 배열 출력하기
    printf("\n짝수 배열:\n");
    PrintArray(evenArray, SIZE);

    // 홀수 배열 출력하기
    printf("\n홀수 배열:\n");
    PrintArray(oddArray, SIZE);

    return 0;
}
