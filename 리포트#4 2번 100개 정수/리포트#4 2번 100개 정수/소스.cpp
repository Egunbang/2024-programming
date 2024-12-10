#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// 무작위 범위 내의 정수를 생성하는 함수
int GenRanNum(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

// 총합, 분산, 표준편차 계산
void CalculStat(int* numbers, int count, double* sum, double* variance, double* std_dev) 
{
    *sum = 0.0;
    *variance = 0.0;

    // 총합 계산
    for (int i = 0; i < count; i++)
    {
        *sum += *(numbers + i);
    }

    double mean = *sum / count;

    // 분산 계산
    for (int i = 0; i < count; i++)
    {
        *variance += (*(numbers + i) - mean) * (*(numbers + i) - mean);
    }
    *variance /= count;

    // 표준편차 계산
    *std_dev = sqrt(*variance);
}

int main(void)
{
    int min_range = 1, max_range = 100; // 무작위 수 생성 범위
    int selected_min = 30, selected_max = 70; // 추출 범위
    int random_numbers[100]; // 100개의 정수를 저장
    int selected_numbers[10]; // 추출된 10개의 정수를 저장
    int count = 0;

    // 난수 생성 초기화
    srand(time(0));

    // 100개의 무작위 정수 생성 및 출력
    printf("100개의 무작위 정수:\n");
    for (int i = 0; i < 100; i++) 
    {
        random_numbers[i] = GenRanNum(min_range, max_range);
        printf("%d ", random_numbers[i]);
        if ((i + 1) % 10 == 0) printf("\n"); // 10개씩 줄바꿈
    }

    // 추출 범위 내에서 10개의 정수 선택
    for (int i = 0; i < 100 && count < 10; i++)
    {
        if (random_numbers[i] >= selected_min && random_numbers[i] <= selected_max)
        {
            selected_numbers[count++] = random_numbers[i];
        }
    }

    // 추출된 정수의 총합, 분산, 표준편차 계산
    if (count == 10) 
    {
        double sum, variance, std_dev;
        CalculStat(selected_numbers, 10, &sum, &variance, &std_dev);

        // 결과 출력
        printf("\n추출된 10개의 정수:\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", selected_numbers[i]);
        }

        printf("\n\n결과:\n");
        printf("총합: %.2f\n", sum);
        printf("분산: %.2f\n", variance);
        printf("표준편차: %.2f\n", std_dev);
    }
    else
    {
        printf("\n추출 범위 내의 정수가 충분하지 않습니다.\n");
    }

    return 0;
}
