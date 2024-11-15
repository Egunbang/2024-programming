#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// ���� ������ 10���� ����, ������ 200���� ����
#define NUM_COUNT 10 
#define RANGE 200

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


// �����Լ�
int main(void) 
{
    int sum = 0; //sum = ����
    double mean, variance = 0.0, stddev; //mean = ���, variance = �л�, stddev = ǥ������
    int num, i;

    // ���� ������ �ʱ�ȭ
    GenRandSeed();

    // 10���� ������ ���� ���� �� ���
    for (i = 0; i < NUM_COUNT; i++) 
    {
        num = GenRandNum(RANGE);
        printf("%d ", num);

        // ���� ���
        sum += num;

        // ������ ���� �л� ���
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

    // ��� ���
    mean = (double)sum / NUM_COUNT;

    // �л� ���
    variance = variance / NUM_COUNT;

    // ǥ������ ���
    stddev = sqrt(variance);

    // ��� ����ϱ�
    printf("����: %d\n", sum);
    printf("���: %.2f\n", mean);
    printf("�л�: %.2f\n", variance);
    printf("ǥ������: %.2f\n", stddev);

    return 0;
}
