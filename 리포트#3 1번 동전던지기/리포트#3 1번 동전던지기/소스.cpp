#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_FLIP 10000
#define COIN_FWD_BWD 3
#define COIN_FWD_STATUS 1
#define COIN_BWD_STATUS 2

#define INITSTATUS 100
#define END_COND 999

// 시간 정보를 사용하여 시드 번호 생성 함수
void GenRandSeed()
{
    // 시간 시드를 이용하는 무작위 숫자 생성 함수
    srand((unsigned int)(time(NULL)));
    return;
}

// 무작위 숫자 생성 함수
unsigned int GenRandFlipCoin(unsigned int nRange)
{
    unsigned int nRes = 0;
    while (1)
    {
        nRes = ((unsigned int)(rand()) % (nRange));
        if ((nRes == COIN_FWD_STATUS) || (nRes == COIN_BWD_STATUS))
            break;
    }
    return nRes;
}

// 메인 함수 
int main(void)
{
    
    GenRandSeed();

    // 각 상태 정의하기
    int nNumSumFwdFlip = 0;
    int nNumSumBwdFlip = 0;
    double dVarFwdFlip = 0.0;
    double dVarBwdFlip = 0.0;
    double dStdevFwdFlip = 0.0;
    double dStdevBwdFlip = 0.0;

    // 무한 루프
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        // 무작위 숫자 생성하기 코인토스, 1: 앞면, 2: 뒷면
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FWD_BWD);

        // 각 상태 계산하기
        switch (nStatusFlipCoin)
        {
        case COIN_FWD_STATUS:
        {
            nNumSumFwdFlip++;
            break;
        }
        case COIN_BWD_STATUS:
        {
            nNumSumBwdFlip++;
            break;
        }
        default:
        {
            printf("please check your main loop or sub function...\n");
            break;
        }
        }
    }


    // 결과 출력하기
    printf("Summation Result:(FWD,BWD):(%d,%d)\n", nNumSumFwdFlip, nNumSumBwdFlip);
    printf("Probability:(FWD,BWD):(%.4lf,%.4lf)\n", (double)(nNumSumFwdFlip) / (NUM_FLIP), (double)(nNumSumBwdFlip) / (NUM_FLIP));
    return 0;
}