#include <stdio.h>

int main(void)
{
	int num;
	printf("���ϴ� �ܼ��� �Է��Ͻÿ�:");
	scanf_s("%d", &num);
	
	switch (num)
	{
	 case 2:
	 case 3:
	 case 4:
	 case 5:
	 case 6:
	 case 7:
	 case 8:
	 case 9:
		for (int i = 1; i<= 9; i++)
		{
			printf("%d * %d = %d\n", num, i,num*i);
		 }
		break;
	 case 10:
		 for (int num = 2; num <= 9; num++) 
		 {
			 printf("%d��:\n", num);
			 for (int i = 1; i <= 9; i++) 
			 {
				 printf("%d x %d =%d\n", num, i, num * i);
			 }
		  }
	 default:
		printf("2���� 9������ ���ڸ� �Է��Ͻÿ�");
		break;
	}
	return 0;
}