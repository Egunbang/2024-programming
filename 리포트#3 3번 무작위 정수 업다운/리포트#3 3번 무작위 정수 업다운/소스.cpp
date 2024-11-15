#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 10
#define RANGE 100

// ���� ������ �ʱ�ȭ �Լ�
void GenRandSeed() 
{
    srand((unsigned int)(time(NULL)));
}

// ���� ���� ���� �Լ�
int GenRandNum(int nRange) 
{
    return rand() % nRange + 1;
}
//���� �Լ�
int main(void) 
{
    int target, guess;    //target = ����� �� ������ ����, guess = ����ڰ� ������ ����
    int tries = 0;        //tries = �õ� Ƚ��

    // ���� ������ �ʱ�ȭ
    GenRandSeed();

    // ��ǻ�Ͱ� ���� ���� ����
    target = GenRandNum(RANGE);

    printf("0���� %d ������ ���ڸ� ���߽ÿ�. ��ȸ�� %d�� �ִ�.\n", RANGE, MAX_TRIES);

    // �ݺ���: ����ڰ� ���ڸ� ���߱���� �ִ� 10���� ��ȸ�� ��
    while (tries < MAX_TRIES) 
    {
        printf("���ڸ� �Է��ϼ���: ");
        scanf_s("%d", &guess);

        // �Էµ� ���ڿ� ���� �ǵ�� ����
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
            printf("����! %d�� ���� ����!\n", tries + 1);
            break;
        }

        tries++; //�õ��� �� ���� �õ� Ƚ���� 1�� ����
    }

    // ���� 10���� ��ȸ ���� ������ ���� ���
    if (tries == MAX_TRIES && guess != target) 
    {
        printf("�ƽ�. ������ %d ������\n", target);
    }

    return 0;
}
