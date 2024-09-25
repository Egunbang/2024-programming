#include <stdio.h>

int main(void)
{
	int base = 0;
	int height = 0;
	
	printf("삼각형의 밑변과 높이를 입력하세요 : ");
	scanf_s("%d%d", &base, &height);
	printf("삼각형의 넓이는 : %d\n 이다", (base * height) / 2);
	
	return 0;
}