#include <stdio.h>

int main(void) 
{
    int num1, num2;

    // ����ڷκ��� �� ���� ���� �Է¹ޱ�
    printf("ù ��° ������ �Է��Ͻÿ�: ");
    scanf_s("%d", &num1);
    printf("�� ��° ������ �Է��Ͻÿ�: ");
    scanf_s("%d", &num2);

    // ��� ���� �Ǻ�
    switch (num2 == 0 ? -1 : num1 % num2) 
    {
    case 0:
        printf("%d�� %d�� ����Դϴ�.\n", num1, num2);
        break;
    
    case -1:
        printf("0���� ���� �� �����ϴ�.\n");
        break;
    
    default:
        printf("%d�� %d�� ����� �ƴմϴ�.\n", num1, num2);
        break;
    }

    return 0;
}
