#include <stdio.h>
void main()
{
	/*
	1
	2	7
	3	8	12
	4	9	13	16
	5	10	14	17	19
	6	11	15	18	20	21
	*/
	int num;
	int oprtor;
	int aXis_y;
	int aXis_x;
	
	printf("Enter the number : ");
	scanf("%d", &num);
	aXis_y = 1;
	aXis_x = 1;

	for (aXis_y = 1; aXis_y  <= num; aXis_y++)
	{
		oprtor = aXis_y;
		printf("  %-2d", aXis_y);
		for (aXis_x = 1; aXis_x < aXis_y; aXis_x++)
		{
			oprtor = oprtor + (num - aXis_x);
			printf(" %-2d", oprtor); 
		}
		if (aXis_x == aXis_y)
		{
			printf("\n");
			aXis_x = 0;
			
		}
	}
}