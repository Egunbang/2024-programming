#include <stdio.h>

int main(void)
{
	float meter,inch, kilogram;
	printf("���� ������ ���̸� �Է��Ͻÿ� : ");
	scanf_s(" %f", &meter);
	printf("%.2f���ʹ� %.2f��Ʈ�Դϴ�\n", meter, meter * 3.28084);

	printf("���� ������ ���̸� �Է��Ͻÿ� : ");
	scanf_s(" %f", &inch);
	printf("%.2f���ʹ� %.2f��ġ�Դϴ�\n", inch, meter * 0.0254);
	
	
	
	printf("ų�α׷� ������ ���Ը� �Է��Ͻÿ�");
	scanf_s("%f", &kilogram);
	printf("%.2fų�α׷��� %.2fslug�̴�\n", kilogram, kilogram * 0.0685);
	return 0;

}