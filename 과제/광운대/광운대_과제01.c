#include <stdio.h>
void main()
{
	/*
	Name : Wontac Jeong
	02. Printing Square
	��������
	��    ��
	��������
	*/
	int num;
	int aXis_x = 0, aXis_y = 0;

	printf("Please enter the number (More than 0):\n");
	scanf_s("%d", &num);

	aXis_x++;		//x1
	aXis_y++;		//y1
	while (aXis_y == 1)
	{
		while (aXis_x <= num)	//if variable y is same as 1, Print ��������.
		{
			if (aXis_x == 1)
			{
				printf("��");
				aXis_x++;
			}
			else if (aXis_x < num)
			{
				printf("����");
				aXis_x++;
			}
			else if (aXis_x == num)
			{
				printf("��\n");
				aXis_x++;
				aXis_y++;
			}
		}
	}		//End of the First Line

	while (aXis_y < num)	//if variable y is less then (num-1), print��  ��
	{
		aXis_x = 1;
		while (aXis_x <= num)
		{
			if (aXis_x == 1)
			{
				printf("��");
				aXis_x++;
			}
			else if (aXis_x < num)
			{
				printf("  ");
				aXis_x++;
			}
			else if (aXis_x == num)
			{
				printf("��\n");
				aXis_x++;
				aXis_y++;
			}

		}
	}	//End of the Middle of Squear 

	while (aXis_y == num)	//if variable y is same as num. print ��������.
	{
		aXis_x = 1;
		while (aXis_x <= num)
		{
			if (aXis_x == 1)
			{
				printf("��");
				aXis_x++;
			}
			else if (aXis_x < num)
			{
				printf("����");
				aXis_x++;
			}
			else if (aXis_x == num)
			{
				printf("��\n");
				aXis_x++;
				aXis_y++;
			}

		}
	}	//End of the Final Line
}