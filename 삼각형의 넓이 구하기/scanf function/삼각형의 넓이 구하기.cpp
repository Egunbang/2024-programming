#include <stdio.h>

int main(void)
{
	int base = 0;
	int height = 0;
	
	printf("�ﰢ���� �غ��� ���̸� �Է��ϼ��� : ");
	scanf_s("%d%d", &base, &height);
	printf("�ﰢ���� ���̴� : %d\n �̴�", (base * height) / 2);
	
	return 0;
}