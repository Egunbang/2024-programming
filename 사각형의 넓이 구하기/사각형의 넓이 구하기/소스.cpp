#include <stdio.h>

int main(void)
{
	int base = 0;
	int height = 0;

	printf("�غ��� ���̸� �Է��Ͻÿ� :");
	scanf_s("%d %d", &base, &height);
	printf("�簢���� ���̴� %.1d\n�̴�", base * height);

	return 0;
}