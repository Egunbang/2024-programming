#include <stdio.h>

int main(void) 
{
    int number;

    // ���� �Է¹ޱ�
    printf("������ �Է��Ͻÿ�: ");
    scanf_s("%d", &number);

    // ¦������ Ȧ������ �Ǻ��ϱ�
    switch (number % 2)   // 2�� �������� �� 0�̸� ù��° ���๮, 1�̸� 2��° ���๮
    {
    case 0:
        printf("%d�� ¦���Դϴ�.\n", number);
        break;
    
    case 1:
        printf("%d�� Ȧ���Դϴ�.\n", number);
        break;
    }

    return 0;
}   
