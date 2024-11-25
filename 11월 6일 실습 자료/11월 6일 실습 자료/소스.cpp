#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//#define COIN_FWD_FLIP 0
//#define COIN_BWD_FLIP 3

#define NUM_FLIP 10000                        // 만번 던질 것
#define COIN_FWD_STATUS 0
#define COIN_BWD_STATUS 1
#define COIN_FWD_BWD 3

#define INITSTATUS 100
#define END_COND 999


// generating the seed number using the time clock information
// 랜덤 숫자 생성 함수 만들기
void GenRandSeed()
{
    //generating the random number using the time seed
    // 랜덤 숫자를 만들기위해 숫자 함수를 사용
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number
// 랜덤 숫자 만들기
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


// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nNumSumFwdFlip = 0;
    int nNumSumBwdFlip = 0;
    double dVarFwdFlip = 0.0;
    double dVarBwdFlip = 0.0;
    double dStdevFwdFlip = 0.0;
    double dStdevBwdFlip = 0.0;

    // infinite loop
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        // generating the random number, Flip Coin, 0: Fwd, 1: Bwd
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FWD_BWD);

    
        // printing result
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
                printf("다시 확인하시오");
            }
        } 
        
    }
    
    printf("결과 : (fwd, bwd):(%d, %d)\n", nNumSumFwdFlip, nNumSumBwdFlip);
    printf("확률 : (fwd, bwd):(%.2lf, %.2if)\n", (double)(nNumSumFwdFlip)/(NUM_FLIP), (double)( nNumSumBwdFlip)/(NUM_FLIP));
    return 0;
}