#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_FLIP 10                 // 배열의 크기 10으로 설정
#define MIN_RANGE -100.0            // 랜덤 숫자 최솟값 -100.0
#define MAX_RANGE 100.0             // 랜덤 숫자 최댓값 100.0

#define MAX_EVEN_NUMBER 10            // 짝수 숫자의 최대 개수
#define MAX_ODD_NUMBER 10             // 홀수 숫자의 최대 개수

// 랜덤 시드 생성 함수
void GenRandSeed()
{
    srand((unsigned int)(time(NULL))); // 현재 시간을 시드로 설정
    return;
}

// 랜덤 숫자 생성 함수 
double GenRand_Number(double Min, double Max)
{
    double scale = rand() / (double)RAND_MAX;   // [0.0, 1.0] 범위로 실수 생성
    return Min + scale * (Max - Min);           // [Min, Max] 범위로 설정
}

// 배열에 랜덤 숫자 채우는 함수
void Array_Rand_Number(double* Array, int Array_Size, double Min, double Max)
{
    for (int i = 0; i < Array_Size; i++)
    {
        Array[i] = GenRand_Number(Min, Max);    // 배열에 랜덤 실수 배정
    }
    return;
}

// 배열 출력 함수
void Print_Array(double* Array, int Array_Size, const char* Name_Function)
{
    printf("%s\n", Name_Function);
    for (int i = 0; i < Array_Size; i++)
    {
        printf("%.2lf ", Array[i]);            // 소수점 둘째 자리까지 출력
        if ((i + 1) % 10 == 0)                 // 10개씩 출력
            printf("\n");
    }
    printf("\n");

    return;
}

// 짝수와 홀수를 분리하는 함수
void Calc_Even_Odd_Array(double* Array, int Array_Size, int* Even_Array, int* Odd_Array, int* Even_Count, int* Odd_Count)
{
    for (int i = 0; i < Array_Size; i++)
    {
        int num = (int)Array[i]; // 실수를 정수로 변환

        if (num % 2 == 0)
        {
            if (*Even_Count < MAX_EVEN_NUMBER)
            {
                Even_Array[*Even_Count] = num; // 짝수 배열에 저장
                (*Even_Count)++;
            }
        }
        else
        {
            if (*Odd_Count < MAX_ODD_NUMBER)
            {
                Odd_Array[*Odd_Count] = num;   // 홀수 배열에 저장
                (*Odd_Count)++;
            }
        }
    }
}

// 짝수와 홀수 배열을 출력하는 함수
void Print_Even_Odd_Array(int* Even_Array, int Even_Count, int* Odd_Array, int Odd_Count)
{
    printf("짝수 숫자 배열:\n");
    for (int i = 0; i < MAX_EVEN_NUMBER; i++)
    {
        if (i < Even_Count)
        {
            printf("%d ", Even_Array[i]);  // 저장된 짝수 출력
        }
        else
        {
            printf(" X ");                   // 사용되지 않은 인덱스 표시
        }
    }
    printf("\n");

    printf("홀수 숫자 배열:\n");
    for (int i = 0; i < MAX_ODD_NUMBER; i++)
    {
        if (i < Odd_Count)
        {
            printf("%d ", Odd_Array[i]);  // 저장된 홀수 출력
        }
        else
        {
            printf(" X ");                  // 사용되지 않은 인덱스 표시
        }
    }
    printf("\n");
}

// 메인 함수
int main(void)
{
    GenRandSeed(); // 랜덤 시드 생성

    double flips[NUM_FLIP];                                                 // 랜덤 숫자 저장 배열

    Array_Rand_Number(flips, NUM_FLIP, MIN_RANGE, MAX_RANGE);               // 배열에 랜덤 숫자 배정

    Print_Array(flips, NUM_FLIP, "랜덤으로 생성된 초기 배열: ");            // 초기 배열 출력

    int Even_Array[MAX_EVEN_NUMBER];                                        // 짝수 저장 배열
    int Odd_Array[MAX_ODD_NUMBER];                                          // 홀수 저장 배열
    int Even_Count = 0;
    int Odd_Count = 0;

    Calc_Even_Odd_Array(flips, NUM_FLIP, Even_Array, Odd_Array, &Even_Count, &Odd_Count);

    Print_Even_Odd_Array(Even_Array, Even_Count, Odd_Array, Odd_Count);     // 짝수와 홀수 배열 출력

    return 0;
}