//main.cpp: This file contains the 'main' function. Program execution begins and end#include <iostream>
#include <iostream>
using namespace std;

void tictactogame();
void displayBoard(char(*arr)[3]);
int checker(char arr[][3],int turn);
int main() {
	char starter;


	cout << "  ::::::::::: ::::::::::: :::::::: ::::::::::: :::      :::::::: ::::::::::: ::::::::  :::::::::: " << endl
		 << "     :+:         :+:    :+:    :+:    :+:   :+: :+:   :+:    :+:    :+:    :+:    :+: :+:         " << endl
		 << "    +:+         +:+    +:+           +:+  +:+   +:+  +:+           +:+    +:+    +:+ +:+          " << endl
		 << "   +#+         +#+    +#+           +#+ +#++:++#++: +#+           +#+    +#+    +:+ +#++:++#      " << endl
		 << "  +#+         +#+    +#+           +#+ +#+     +#+ +#+           +#+    +#+    +#+ +#+            " << endl
		 << " #+#         #+#    #+#    #+#    #+# #+#     #+# #+#    #+#    #+#    #+#    #+# #+#             " << endl
	   	 << "###     ########### ########     ### ###     ###  ########     ###     ########  ##########       " << endl;
		
	cout << " PRESS TYPE ANYTHINGS TO START"<< endl;
	cin >> starter;

	tictactogame();
	return 0;
	}


void tictactogame()		//���� �Լ�
{
	char board[3][3] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
	};
	int turn = 0;
	int pos = 0;
	char* flag = NULL;	//������ �̿�, ���� ����ȭ
	bool endgame = false;
	char restarter = 'y';

	while (endgame == false) {
		displayBoard(board);
		turn++;
		while (endgame == false) {
			if (turn % 2 == 1)
				cout << "O Turn :";
			else
				cout << "X Turn :";
			cin >> pos;

			switch (pos) {		//���� ��ǥ 9�� ��ġ�� ����
			case 1:
				flag = &board[0][0];
				break;
			case 2:
				flag = &board[0][1];
				break;
			case 3:
				flag = &board[0][2];
				break;
			case 4:
				flag = &board[1][0];
				break;
			case 5:
				flag = &board[1][1];
				break;
			case 6:
				flag = &board[1][2];
				break;
			case 7:
				flag = &board[2][0];
				break;
			case 8:
				flag = &board[2][1];
				break;
			case 9:
				flag = &board[2][2];
				break;
			default:
				(cin.fail());
				cin.clear();
				cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');	//cin ���ѷ��� ����
				break;
			}
			if (flag == NULL) {		//��������1 1�� �߸��� ���� �Է½�.
				displayBoard(board);
			}
			else if (*flag == 'O' || *flag == 'X')	//������ ���� ����
			{
				displayBoard(board);
				if (0 < pos && pos < 10)
					cout << "Aready marked. Try Again" << endl;
			}
			else
				if (turn % 2 == 1) {		//��ŷ����
					*flag = 'O';
					break;
				}
				else {
					*flag = 'X';
					break;
				}
		}
		switch (checker(board, turn)) {
		case 0:
			break;
		case 1:
			displayBoard(board);
			cout << "PLAYER O WIN" << endl;
			endgame = true;
			break;
		case 2:
			displayBoard(board);
			cout << "PLAYER X WIN" << endl;
			endgame = true;
			break;
		case 3:
			displayBoard(board);
			cout << "DRAW" << endl;
			endgame = true;
			break;
		}
	}
		cout << "Play Again? (y or n)"<< endl;
		while (restarter != 'n') {
			cout << "You :";
			cin >> restarter;
			switch (restarter) {
			case 'y':
				tictactogame();
				break;
			case 'n':
				break;
			default:
				(cin.fail());
				cin.clear();
				cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');	//cin ���ѷ��� ����
				break;
			}
		}
	};

	void displayBoard(char(*arr)[3]) {		//������ ������
		system("CLS");
		cout << "��������������������������" << endl;
		cout << "�� " << arr[0][0] << " �� " << arr[0][1] << " �� " << arr[0][2] << " �� " << endl;
		cout << "��������������������������" << endl;
		cout << "�� " << arr[1][0] << " �� " << arr[1][1] << " �� " << arr[1][2] << " �� " << endl;
		cout << "��������������������������" << endl;
		cout << "�� " << arr[2][0] << " �� " << arr[2][1] << " �� " << arr[2][2] << " �� " << endl;
		cout << "��������������������������" << endl;
	};

	int checker(char arr[][3],int turn) {	//0 == �����簳 1 == 1�� �¸� 2 == 2���¸� 3 == ���º�
		char* flagcolor = NULL;
		if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]) {		//1 2 3 ������
			flagcolor = &arr[0][0];									//�ش���� ���� Ȯ����
			if (*flagcolor == 79 )
				return 1;
			else
				return 2;
		}
		else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2]) {	//4 5 6 ������
			flagcolor = &arr[1][0];										//�ش���� ���� Ȯ����
			if (*flagcolor == 79)										//�º� �ǰ�
				return 1;
			else
				return 2;
		}
		else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2]) {	//7 8 9 ������
			flagcolor = &arr[2][0];										//�ش���� ���� Ȯ����
			if (*flagcolor == 79)										//�º� �ǰ�
				return 1;
			else
				return 2;
		}
		else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]) {	//7 4 1 ������
			flagcolor = &arr[0][0];										//�ش���� ���� Ȯ����
			if (*flagcolor == 79)										//�º� �ǰ�
				return 1;
			else
				return 2;
		}
		else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]) {	//7 4 1 ������
			flagcolor = &arr[0][0];										//�ش���� ���� Ȯ����
			if (*flagcolor == 79)										//�º� �ǰ�
				return 1;
			else
				return 2;
		}
		else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1]) {	//8 5 2 ������
			flagcolor = &arr[0][1];										//�ش���� ���� Ȯ����
			if (*flagcolor == 79)										//�º� �ǰ�
				return 1;
			else
				return 2;
		}
		else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2]) {	//9 6 3 ������
			flagcolor = &arr[0][2];										//�ش���� ���� Ȯ����
			if (*flagcolor == 79)										//�º� �ǰ�
				return 1;
			else
				return 2;
		}
		else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {	//7 5 3 ������
			flagcolor = &arr[0][0];										//�ش���� ���� Ȯ����
			if (*flagcolor == 79)										//�º� �ǰ�
				return 1;
			else
				return 2;
		}
		else if (arr[2][0] == arr[1][1] && arr[2][0] == arr[0][2]) {	//9 5 1 ������
			flagcolor = &arr[0][2];										//�ش���� ���� Ȯ����
			if (*flagcolor == 79)										//�º� �ǰ�
				return 1;
			else
				return 2;
		}
		else if (turn == 9)												//9�� ���� �ºΰ� ���� �������.
			return 3;
		else															//�׿� ������ ���� �簳
			return 0;
	};