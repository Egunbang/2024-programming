#include <stdio.h>

int main(void)
{
	FILE* fp;

	fp = fopen("dlrjsdnd.txt", "r");
	if (fp == NULL)
	{
		printf("파일이 열리지 않았다.\n");
		return 1;
	}
	printf("파일리 열렸다.\n");
	fclose(fp);

	return 0;
}