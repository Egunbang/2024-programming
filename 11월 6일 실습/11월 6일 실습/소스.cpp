#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define nonflip 10000
#define INITSTATUS 100
#define END_COND 999
#define coin_fwd_bwd 2
#define coin_fwd_status 1
#define coin_bwd_status 0


int nRes = INITSTATUS;
// generating the seed number using the time clock information
void GenRandSeed()
{
    // generating the random number using the time seed
    srand((unsigned int)(time(NULL)));
    return;
}

// generating the random number
unsigned int GenRandNum(unsigned int nRange)
{
    unsigned int nRes = 0;
    unsigned int nNum = rand();
    while (1)
    {
        nRes = ((unsigned int)(nNum) % (nRange));
        if ((nRes == coin_fwd_status) || (nRes == coin_fwd_bwd))
        {
            printf("nRes:%d\n", nRes);
            break;
        }       
    }  
    return nRes;  
}

// calculating result

// main function loop
int main(void)
{
    // assigning seed
    GenRandSeed();

    // initializing variables
    int nNumsumFwdflip = 0;
    int nNumsumBwdflip = 0;
    double dVarFwdflip = 0.0;
    double dVarBwdflip = 0.0;
    double dStdevFwdflip = 0.0;
    double dStdevBWDFLIP = 0.0;


    
    while (1)
    {

        // generating the random number, FLIP COIN  0: Fwd 1:Bwd
        unsigned int statusflipcoin = GenRandNum(coin_fwd_bwd);

        // calculating result
        printf("Input Your Status(ROCK:0, PAPER:1, SCISSORS:2):\n");
        printf("if you want to end the loop, please input 999\n");
        scanf_s("%d", &nNumsumFwdflip);

        // exception #1, end condition
        if (nNumsumFwdflip == END_COND)
        {
            printf("end of the infinite while loop RPS game...\n");
            break;
        }

        return 0;
    }
}
