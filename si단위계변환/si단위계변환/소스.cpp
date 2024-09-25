#include <stdio.h>

int main(void)
{
	float meter,inch, kilogram;
	printf("미터 단위의 길이를 입력하시오 : ");
	scanf_s(" %f", &meter);
	printf("%.2f미터는 %.2f피트입니다\n", meter, meter * 3.28084);

	printf("미터 단위의 길이를 입력하시오 : ");
	scanf_s(" %f", &inch);
	printf("%.2f미터는 %.2f인치입니다\n", inch, meter * 0.0254);
	
	
	
	printf("킬로그램 단위의 무게를 입력하시오");
	scanf_s("%f", &kilogram);
	printf("%.2f킬로그램은 %.2fslug이다\n", kilogram, kilogram * 0.0685);
	return 0;

}