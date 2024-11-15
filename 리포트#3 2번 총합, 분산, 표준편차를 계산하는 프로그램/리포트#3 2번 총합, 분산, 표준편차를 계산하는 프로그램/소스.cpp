#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// 숫자 개수를 10개로 정의, 범위를 200으로 정의
#define NUM_COUNT 10 
#define RANGE 200

// 난수 생성기 초기화 함수
void GenRandSeed() 
{
    srand((unsigned int)(time(NULL)));
}

// 랜덤 숫자 생성 함수
int GenRandNum(int nRange) 
{
    return rand() % nRange + 1;
}


// 메인함수
int main(void) 
{
    int sum = 0; //sum = 총합
    double mean, variance = 0.0, stddev; //mean = 평균, variance = 분산, stddev = 표준편차
    int num, i;

    // 난수 생성기 초기화
    GenRandSeed();

    // 10개의 무작위 정수 생성 및 출력
    for (i = 0; i < NUM_COUNT; i++) 
    {
        num = GenRandNum(RANGE);
        printf("%d ", num);

        // 총합 계산
        sum += num;

        // 범위에 따른 분산 계산
        if (num <= RANGE / 2) 
        {
            variance += pow(num - (RANGE / 4), 2);
        }
        else 
        {
            variance += pow(num - (3 * RANGE / 4), 2);
        }
    }
    printf("\n");

    // 평균 계산
    mean = (double)sum / NUM_COUNT;

    // 분산 계산
    variance = variance / NUM_COUNT;

    // 표준편차 계산
    stddev = sqrt(variance);

    // 결과 출력하기
    printf("총합: %d\n", sum);
    printf("평균: %.2f\n", mean);
    printf("분산: %.2f\n", variance);
    printf("표준편차: %.2f\n", stddev);

    return 0;
}
