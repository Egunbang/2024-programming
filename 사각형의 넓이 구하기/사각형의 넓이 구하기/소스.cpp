#include <stdio.h>

int main(void)
{
	int base = 0;
	int height = 0;

	printf("밑변과 높이를 입력하시오 :");
	scanf_s("%d %d", &base, &height);
	printf("사각형의 넓이는 %.1d\n이다", base * height);

	return 0;
}