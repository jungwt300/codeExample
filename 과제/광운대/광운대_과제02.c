#include <stdio.h>
void main()
{
	int n, r;			//Immovable variable
	int out_n, out_r;	//output

	printf("n°ª: ");
	scanf_s("%d", &n);	//inputing n
	printf("r°ª: ");
	scanf_s("%d", &r);	//inputing r

	out_n = n;
	out_r = r;

	for (int i = 1; n > (n - r) + i; i++)	//value n
		/*
		if	5C2	:	5 > (5 - 2) + 1 (multiple)	>>	5 > (5 - 2) + 2	(multiple)									2 times
		if	5C3	:	5 > (5 - 3) + 1 (multiple)	>>	5 > (5 - 3) + 2	(multiple)	>>	5 > (5 - 3) + 3	(multiple)	3 times
		*/
	{
		out_n = out_n * ((n - r) + i);
	}
	for (int i = 1; r > i; i++)	//value r		>>	r!	=	1 x 2 x 3 x - x (n-2) x (n-1) x n 
	{
		out_r = out_r * i;			
		/*
		if r = 4	>>	output = 4 x 1
						output = (output:4x1) x 2
						output = (output:4x1x2) x 3
						output = (output:4x1x2x3) x 4
						output = 1 x 2 x 3 x 4 = 4!
		*/
	}

	printf("n : %d\n", out_n);
	printf("r : %d\n", out_r);

	printf("%dC%d %d \n", n, r, out_n / out_r);

}