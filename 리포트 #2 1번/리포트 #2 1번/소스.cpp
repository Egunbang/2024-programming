#include <stdio.h>

int main(void) 
{
    int number;

    // ���� �Է¹ޱ�
    printf("������ �Է��Ͻÿ�: ");
    scanf_s("%d", &number);

    // ¦������ Ȧ������ �Ǻ��ϱ�
    if (number %2 == 0)  //2�� �������� �� 0�̸� ù��° ���๮, 0�� �ƴϸ� �ι�° ���๮
    {
        printf("%d�� ¦���̴�.\n", number);
    }
    else 
    {
        printf("%d�� Ȧ���̴�.\n", number);
    }

    return 0;
}
