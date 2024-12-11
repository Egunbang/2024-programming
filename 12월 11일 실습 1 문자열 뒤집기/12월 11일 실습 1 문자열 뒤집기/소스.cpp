#include <stdio.h>
#include <string.h>

void ReverseWord(char* start, char* end)
{
    //������ ���۰� �� �����͸� �޾� ���ڸ� �����´�. 
    char temp;
    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main(void) 
{
    char str[1000];
    printf("���ڿ��� �Է��ϼ���: ");
    fgets(str, sizeof(str), stdin);

    // �Է¹��� ���ڿ����� '\n'�� ����
    str[strcspn(str, "\n")] = '\0';

    char* word_start = str;
    char* temp = str;

    // �� �ܾ ������
    while (*temp) 
    {
        temp++;
        if (*temp == '\0' || *temp == ' ') 
        {
            ReverseWord(word_start, temp - 1);
            word_start = temp + 1;
        }
    }

    printf("������ ���ڿ�: %s\n", str);

    return 0;
}