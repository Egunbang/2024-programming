#include <stdio.h>

int main(void)
{
	int length;
	int height;
	double radius = 0;

	printf("���̿� ����, �������� �Է��Ͻÿ� :");
	scanf_s("%d %d %lf", &length ,&height, &radius);
	printf("�ﰢ���� ���̴� : %d�̴�\n", length * height);
	printf("�簢���� ���̴� : %d�̴�\n", length * height * 1 / 2);
	printf("���� ���̴� : %.2lf�̴�\n", radius * radius * 3.14);
	printf("���� ǥ������ : %.2lf�̴�\n", radius * radius  * 3.14*4);
	printf("���� ü���� : %.2lf�̴�\n", radius * radius * radius * 3.14 * 4 / 3);
	
	return 0;
}