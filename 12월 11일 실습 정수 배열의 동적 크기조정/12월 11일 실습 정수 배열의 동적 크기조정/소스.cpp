#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 배열의 총합, 평균, 분산, 표준편차를 계산하는 함수
void calculateStatistics(int* arr, int size, int* sum, double* mean, double* variance, double* std_dev) 
{
    *sum = 0;
    double variance_sum = 0.0;

    // 총합 계산
    for (int i = 0; i < size; i++) 
    {
        *sum += *(arr + i);
    }

    // 평균 계산
    *mean = (double)(*sum) / size;

    // 분산 계산
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

    // 초기 배열 크기 입력받기
    printf("초기 배열의 크기를 입력하세요: ");
    scanf_s("%d", &initial_size);

    // 배열 동적 할당
    arr = (int*)malloc(initial_size * sizeof(int));
    if (arr == NULL) {
        printf("메모리 할당 실패");
        return 1;
    }

    // 초기 배열 값 입력받기
    printf("초기 배열의 값을 입력하세요:");
    for (int i = 0; i < initial_size; i++) 
    {
        scanf_s("%d", arr + i);
    }

    // 초기 배열의 총합, 평균, 분산, 표준편차 계산
    calculateStatistics(arr, initial_size, &sum, &mean, &variance, &std_dev);
    printf("초기 배열 - 총합: %d, 평균: %.2f, 분산: %.2f, 표준편차: %.2f\n", sum, mean, variance, std_dev);

    // 추가 배열 크기 입력받기
    printf("추가할 배열의 크기를 입력하세요: ");
    scanf_s("%d", &additional_size);

    // 배열 크기 재할당
    arr = (int*)realloc(arr, (initial_size + additional_size) * sizeof(int));
    if (arr == NULL)
    {
        printf("메모리 재할당 실패\n");
        return 1;
    }

    // 추가 배열 값 입력받기
    printf("추가 배열의 값을 입력하세요:");
    for (int i = initial_size; i < initial_size + additional_size; i++) 
    {
        scanf_s("%d", arr + i);
    }

    // 추가된 배열의 총합, 평균, 분산, 표준편차 계산
    calculateStatistics(arr, initial_size + additional_size, &sum, &mean, &variance, &std_dev);
    printf("추가된 배열 - 총합: %d, 평균: %.2f, 분산: %.2f, 표준편차: %.2f", sum, mean, variance, std_dev);

    // 메모리 해제
    free(arr);

    return 0;
}
