#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Rock_Paper_Scissors 3
#define ROCK 0
#define PAPER 1
#define SCISSORS 2
#define INITSTATUS 100
#define END_COND 999

#define PLAYER WIN 12
#define PLAYER LOSE 13
#define DRAW 14
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
    nRes = ((unsigned int)(nNum) % (nRange));
    return nRes;
}

//initializing variabies
unsigned int Ncomrus = INITSTATUS;
unsigned int NplayerRps = INITSTATUS;




int main(void)
{
    int nRange = 0;

    //infinite loop
    while (1)
    {
        printf("입력하시오(rock :0, paper :1, scissors:2):\n");
        printf("끝내고 싶우면 999를 눌러라\n");
        scanf_s("%d", &NplayerRps);

        if (NplayerRps == END_COND)
        {
            printf("게임을 끝냄\n");
            break;
        }

        if ((NplayerRps < 0) || (NplayerRps >= Rock_Paper_Scissors))
        {
            printf("다시 확인하라\n");
            continue;
        }

         unsigned int nComRps = GenRandNum(nRange  = (Rock_Paper_Scissors));

         unsigned int nComRps = GenRandNum(nRange = (Rock_Paper_Scissors));

          printf("사용자, 컴퓨터):(%d,%d)\n\n",NplayerRps, nComRps);

          
         
















    }


    system("pause");
    return 0;
}