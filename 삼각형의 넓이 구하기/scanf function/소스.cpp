#include <stdio.h>

int main(void)
{
	float base, height;

	printf("�簢���� �غ��� ���̸� �Է��ϼ��� ");
	scanf_s("%f %f", &base, &height);
	printf("�簢���� ���̴� : %.2f\n", (base * height) / 1 );

	return 0;
}