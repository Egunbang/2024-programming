#include <stdio.h>

int main(void)
{
	float meter, kilogram;
	printf("���� ������ ���̸� �Է��Ͻÿ� : ");
	scanf_s(" %f", &meter);
	printf("%.2f���ʹ� %.2f��Ʈ�Դϴ�\n", meter, meter * 3.28084);

	printf("ų�α׷� ������ ���Ը� �Է��Ͻÿ�");
	scanf_s("%f", &kilogram);
	printf("%.2fų�α׷��� %.2f�Ŀ���̴�\n", kilogram, kilogram * 2.20462);
	return 0;

}