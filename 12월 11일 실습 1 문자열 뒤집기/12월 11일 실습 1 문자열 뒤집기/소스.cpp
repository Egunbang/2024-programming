#include <stdio.h>
#include <string.h>

void ReverseWord(char* start, char* end)
{
    //문자의 시작과 끝 포인터를 받아 문자를 뒤집는다. 
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
    printf("문자열을 입력하세요: ");
    fgets(str, sizeof(str), stdin);

    // 입력받은 문자열에서 '\n'을 제거
    str[strcspn(str, "\n")] = '\0';

    char* word_start = str;
    char* temp = str;

    // 각 단어를 뒤집기
    while (*temp) 
    {
        temp++;
        if (*temp == '\0' || *temp == ' ') 
        {
            ReverseWord(word_start, temp - 1);
            word_start = temp + 1;
        }
    }

    printf("뒤집힌 문자열: %s\n", str);

    return 0;
}