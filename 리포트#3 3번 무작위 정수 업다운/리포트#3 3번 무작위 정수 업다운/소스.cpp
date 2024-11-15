#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define RANGE 100

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
//메인 함수
int main(void) 
{
    int target, guess;    //target = 맞춰야 할 랜덤한 숫자, guess = 사용자가 예측한 숫자
    int tries = 0;        //tries = 시도 횟수

    // 난수 생성기 초기화
    GenRandSeed();

    // 컴퓨터가 맞출 숫자 생성
    target = GenRandNum(RANGE);

    printf("0부터 %d 사이의 숫자를 맞추시오. 기회는 %d번 있다.\n", RANGE, MAX_TRIES);

    // 반복문: 사용자가 숫자를 맞추기까지 최대 10번의 기회를 줌
    while (tries < MAX_TRIES) 
    {
        printf("숫자를 입력하세요: ");
        scanf_s("%d", &guess);

        // 입력된 숫자에 따라 피드백 제공
        if (guess < target) 
        {
            printf("UP!\n");
        }

        else if (guess > target) 
        {
            printf("DOWN!\n");
        }

        else 
        {
            printf("정답! %d번 만에 맞춤!\n", tries + 1);
            break;
        }

        tries++; //시도할 때 마다 시도 횟수가 1씩 증가
    }

    // 만약 10번의 기회 내에 맞추지 못한 경우
    if (tries == MAX_TRIES && guess != target) 
    {
        printf("아쉽. 정답은 %d ㅋㅋㅋ\n", target);
    }

    return 0;
}
