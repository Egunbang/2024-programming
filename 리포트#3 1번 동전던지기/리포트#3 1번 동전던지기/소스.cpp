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

// �ð� ������ ����Ͽ� �õ� ��ȣ ���� �Լ�
void GenRandSeed()
{
    // �ð� �õ带 �̿��ϴ� ������ ���� ���� �Լ�
    srand((unsigned int)(time(NULL)));
    return;
}

// ������ ���� ���� �Լ�
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

// ���� �Լ� 
int main(void)
{
    
    GenRandSeed();

    // �� ���� �����ϱ�
    int nNumSumFwdFlip = 0;
    int nNumSumBwdFlip = 0;
    double dVarFwdFlip = 0.0;
    double dVarBwdFlip = 0.0;
    double dStdevFwdFlip = 0.0;
    double dStdevBwdFlip = 0.0;

    // ���� ����
    for (unsigned int i = 0; i < NUM_FLIP; i++)
    {
        // ������ ���� �����ϱ� �����佺, 1: �ո�, 2: �޸�
        unsigned int nStatusFlipCoin = GenRandFlipCoin(COIN_FWD_BWD);

        // �� ���� ����ϱ�
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


    // ��� ����ϱ�
    printf("Summation Result:(FWD,BWD):(%d,%d)\n", nNumSumFwdFlip, nNumSumBwdFlip);
    printf("Probability:(FWD,BWD):(%.4lf,%.4lf)\n", (double)(nNumSumFwdFlip) / (NUM_FLIP), (double)(nNumSumBwdFlip) / (NUM_FLIP));
    return 0;
}