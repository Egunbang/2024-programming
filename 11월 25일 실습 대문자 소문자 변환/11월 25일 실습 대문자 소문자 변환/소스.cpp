#include <stdio.h>

int main(void)
{
    char str[100];  // 입력받을 문장을 저장할 배열만들기
    int count = 0;  // 바뀐 문자의 수 초기화하기

    // 문장 입력 받기
    printf("문장을 입력하세요: ");
    fgets(str, sizeof(str), stdin);

    // 대문자를 소문자로 변환
    for (int i = 0; str[i] != '\0'; i++) 
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A');
            count++;
        }
    }

    // 결과 출력
    printf("변환된 문장: %s", str);
    printf("바뀐 문자의 수: %d\n", count);

    return 0;
}
