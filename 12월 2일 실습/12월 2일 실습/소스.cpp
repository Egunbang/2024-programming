#include <stdio.h>

void SetArray(double* pDArr, int nArrSize)
{
	printf("input:size(%d) array\n", nArrSize);
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		scanf_s("%lf", pDArr + i);
	}
}
	void PrintArray(double* pDArr, int nArrSize)
	{
		for (unsigned int i = 0; i < nArrSize; i++)
		{
			printf("[%d](%u, %.4lf)\n", i, pDArr + i, *(pDArr + i));
		}
	}

	double CalcMaxValArray(double* pDArr, int nArrSize)
	{
		double dRes = *(pDArr + 0);
		for (unsigned int i = 0; i < nArrSize; i++)
		{
			if (*(pDArr + i) > dRes)
				dRes = *(pDArr + i);
		}
		return dRes;
	}
	
	
	
	int main(void)
	{
		double dArr[5] = {};
		double* pDArr = dArr;
			int nArrSize = sizeof(dArr) / sizeof(dArr[0]);

		SetArray(pDArr, nArrSize);
		PrintArray(pDArr, nArrSize);

		for (unsigned int i = 0; i < nArrSize; i++)
		{
			printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
			printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
			printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
			printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
		}
		printf("[MaxVal](%.4lf)\n", CalcMaxValArray(pDArr, nArrSize));
		return 0;
	}

	





