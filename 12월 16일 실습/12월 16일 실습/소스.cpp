#include <stdio.h>

int main(void)
{
	FILE* fp;

	fp = fopen("dlrjsdnd.txt", "r");
	if (fp == NULL)
	{
		printf("������ ������ �ʾҴ�.\n");
		return 1;
	}
	printf("���ϸ� ���ȴ�.\n");
	fclose(fp);

	return 0;
}