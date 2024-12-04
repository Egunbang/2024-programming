#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10//배열 크기는 10

//배열의 상태를 출력하는 함수
void PrintArray(double* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%.2f ", array[i]);//소수점 둘째자리까지만 출력
    }
    printf("\n");
}

//배열을 정렬
void CalcSortArray(double* array, int size, int ascending)
{
    //버블 정렬을 사용하여 배열 정렬
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            //오름차순
            if (ascending && array[j] > array[j + 1])
            {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            //내림차순
            else if (!ascending && array[j] < array[j + 1])
            {
                double temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    double array[SIZE];
    int choiceType, choiceSort;

    srand(time(NULL));

    //실수, 정수 선택
    printf("랜덤으로 생성할 수를 선택-(1: 정수, 2: 실수): ");
    scanf_s("%d", &choiceType);

    //배열 생성
    for (int i = 0; i < SIZE; i++)
    {
        if (choiceType == 1)
        {
            //정수 생성 (0 ~ 100)
            array[i] = rand() % 101;
        }
        else if (choiceType == 2)
        {
            //실수 생성 (-100.0 ~ +100.0)
            array[i] = ((double)rand() / RAND_MAX) * 200.0 - 100.0;
        }
        else
        {
            printf("잘못된 접근.\n");
            return 1;
        }
    }

    //랜덤 생성된 배열 출력
    printf("랜덤 생성된 배열: ");
    PrintArray(array, SIZE);

    //정렬 방식 선택
    printf("정렬 방식을 선택하세요 (1: 오름차순, 2: 내림차순): ");
    scanf_s("%d", &choiceSort);

    //선택에 따라 정렬
    if (choiceSort == 1)
    {
        CalcSortArray(array, SIZE, 1); //오름차순 정렬
        printf("오름차순 정렬된 배열: ");
    }
    else if (choiceSort == 2)
    {
        CalcSortArray(array, SIZE, 0); //내림차순 정렬
        printf("내림차순 정렬된 배열: ");
    }
    else
    {
        printf("잘못된 접근.\n");//예외 처리
        return 1;
    }

    // 정렬된 배열 출력
    PrintArray(array, SIZE);

    return 0;
}