#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// ������ ���� ���� ������ �����ϴ� �Լ�
int GenRanNum(int min, int max) 
{
    return rand() % (max - min + 1) + min;
}

// ����, �л�, ǥ������ ���
void CalculStat(int* numbers, int count, double* sum, double* variance, double* std_dev) 
{
    *sum = 0.0;
    *variance = 0.0;

    // ���� ���
    for (int i = 0; i < count; i++)
    {
        *sum += *(numbers + i);
    }

    double mean = *sum / count;

    // �л� ���
    for (int i = 0; i < count; i++)
    {
        *variance += (*(numbers + i) - mean) * (*(numbers + i) - mean);
    }
    *variance /= count;

    // ǥ������ ���
    *std_dev = sqrt(*variance);
}

int main(void)
{
    int min_range = 1, max_range = 100; // ������ �� ���� ����
    int selected_min = 30, selected_max = 70; // ���� ����
    int random_numbers[100]; // 100���� ������ ����
    int selected_numbers[10]; // ����� 10���� ������ ����
    int count = 0;

    // ���� ���� �ʱ�ȭ
    srand(time(0));

    // 100���� ������ ���� ���� �� ���
    printf("100���� ������ ����:\n");
    for (int i = 0; i < 100; i++) 
    {
        random_numbers[i] = GenRanNum(min_range, max_range);
        printf("%d ", random_numbers[i]);
        if ((i + 1) % 10 == 0) printf("\n"); // 10���� �ٹٲ�
    }

    // ���� ���� ������ 10���� ���� ����
    for (int i = 0; i < 100 && count < 10; i++)
    {
        if (random_numbers[i] >= selected_min && random_numbers[i] <= selected_max)
        {
            selected_numbers[count++] = random_numbers[i];
        }
    }

    // ����� ������ ����, �л�, ǥ������ ���
    if (count == 10) 
    {
        double sum, variance, std_dev;
        CalculStat(selected_numbers, 10, &sum, &variance, &std_dev);

        // ��� ���
        printf("\n����� 10���� ����:\n");
        for (int i = 0; i < 10; i++)
        {
            printf("%d ", selected_numbers[i]);
        }

        printf("\n\n���:\n");
        printf("����: %.2f\n", sum);
        printf("�л�: %.2f\n", variance);
        printf("ǥ������: %.2f\n", std_dev);
    }
    else
    {
        printf("\n���� ���� ���� ������ ������� �ʽ��ϴ�.\n");
    }

    return 0;
}
