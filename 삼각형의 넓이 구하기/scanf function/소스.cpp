#include <stdio.h>

int main(void)
{
	float base, height;

	printf("사각형의 밑변과 높이를 입력하세요 ");
	scanf_s("%f %f", &base, &height);
	printf("사각형의 넓이는 : %.2f\n", (base * height) / 1 );

	return 0;
}