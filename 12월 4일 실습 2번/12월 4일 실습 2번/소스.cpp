#include <stdio.h>
#include <stdlib.h> 
#include <time.h>   

// 배열의 역순을 계산하는 함수
void CalcInverseArray(double* arr, double* inverseArr, int size)
{
    // 배열을 역순으로 저장
    for (int i = 0; i < size; i++)
    {
        inverseArr[i] = arr[size - 1 - i];
    }
}

// 배열을 출력하는 함수
void PrintArray(const double* arr, int size, const char* msg)
{
    printf("%s: ", msg);
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", arr[i]); //소수점 둘째자리까지만 출력
    }
    printf("\n");
}

int main(void)
{
    const int SIZE = 10; //배열의 크기
    double arr[SIZE];    //원본 배열
    double inverseArr[SIZE]; //역순 배열
    int choice; //정수 실수 선택

    //정수 또는 실수를 선택
    printf("랜덤으로 생성할 수를 선택-(1: 정수, 2: 실수): ");
    scanf_s("%d", &choice);

    // 랜덤 시드 초기화
    srand((unsigned int)time(NULL));

    //선택에 따라 정수 또는 실수 배열 생성
    if (choice == 1)
    {
        //정수형 배열 생성 (-100 ~ +100)
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = (double)(rand() % 201 - 100);
        }
    }
    else if (choice == 2) {
        //실수형 배열 생성 (-100.0 ~ +100.0)
        for (int i = 0; i < SIZE; i++)
        {
            arr[i] = (double)rand() / RAND_MAX * 200.0 - 100.0;
        }
    }
    else {
        printf("잘못된 접근.\n");
        return 1; //예외처리
    }

    //생성된 배열 출력
    PrintArray(arr, SIZE, "생성된 배열");

    //역순 배열 계산
    CalcInverseArray(arr, inverseArr, SIZE);

    //역순 배열 출력
    PrintArray(inverseArr, SIZE, "역순 배열");

    return 0;
}