#include <stdio.h>

int main(void)
{
    char str[100];  // �Է¹��� ������ ������ �迭�����
    int count = 0;  // �ٲ� ������ �� �ʱ�ȭ�ϱ�

    // ���� �Է� �ޱ�
    printf("������ �Է��ϼ���: ");
    fgets(str, sizeof(str), stdin);

    // �빮�ڸ� �ҹ��ڷ� ��ȯ
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
            count++;
        }
    }

    // ��� ���
    printf("��ȯ�� ����: %s", str);
    printf("�ٲ� ������ ��: %d\n", count);

    return 0;
}
