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


void tictactogame()		//게임 함수
{
	char board[3][3] = {
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
	};
	int turn = 0;
	int pos = 0;
	char* flag = NULL;	//포인터 이용, 절차 간소화
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

			switch (pos) {		//보드 좌표 9개 위치값 저장
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
				cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');	//cin 무한루프 방지
				break;
			}
			if (flag == NULL) {		//오류방지1 1턴 잘못된 변수 입력시.
				displayBoard(board);
			}
			else if (*flag == 'O' || *flag == 'X')	//역참조 오류 구간
			{
				displayBoard(board);
				if (0 < pos && pos < 10)
					cout << "Aready marked. Try Again" << endl;
			}
			else
				if (turn % 2 == 1) {		//마킹구간
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
				cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');	//cin 무한루프 방지
				break;
			}
		}
	};

	void displayBoard(char(*arr)[3]) {		//게임판 렌더러
		system("CLS");
		cout << "┏━━━┳━━━┳━━━┓" << endl;
		cout << "┃ " << arr[0][0] << " ┃ " << arr[0][1] << " ┃ " << arr[0][2] << " ┃ " << endl;
		cout << "┣━━━╋━━━╋━━━┫" << endl;
		cout << "┃ " << arr[1][0] << " ┃ " << arr[1][1] << " ┃ " << arr[1][2] << " ┃ " << endl;
		cout << "┣━━━╋━━━╋━━━┫" << endl;
		cout << "┃ " << arr[2][0] << " ┃ " << arr[2][1] << " ┃ " << arr[2][2] << " ┃ " << endl;
		cout << "┗━━━┻━━━┻━━━┛" << endl;
	};

	int checker(char arr[][3],int turn) {	//0 == 게임재개 1 == 1번 승리 2 == 2번승리 3 == 무승부
		char* flagcolor = NULL;
		if (arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]) {		//1 2 3 같을때
			flagcolor = &arr[0][0];									//해당라인 문자 확인후
			if (*flagcolor == 79 )
				return 1;
			else
				return 2;
		}
		else if (arr[1][0] == arr[1][1] && arr[1][0] == arr[1][2]) {	//4 5 6 같을때
			flagcolor = &arr[1][0];										//해당라인 문자 확인후
			if (*flagcolor == 79)										//승부 판결
				return 1;
			else
				return 2;
		}
		else if (arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2]) {	//7 8 9 같을때
			flagcolor = &arr[2][0];										//해당라인 문자 확인후
			if (*flagcolor == 79)										//승부 판결
				return 1;
			else
				return 2;
		}
		else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]) {	//7 4 1 같을때
			flagcolor = &arr[0][0];										//해당라인 문자 확인후
			if (*flagcolor == 79)										//승부 판결
				return 1;
			else
				return 2;
		}
		else if (arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]) {	//7 4 1 같을때
			flagcolor = &arr[0][0];										//해당라인 문자 확인후
			if (*flagcolor == 79)										//승부 판결
				return 1;
			else
				return 2;
		}
		else if (arr[0][1] == arr[1][1] && arr[0][1] == arr[2][1]) {	//8 5 2 같을때
			flagcolor = &arr[0][1];										//해당라인 문자 확인후
			if (*flagcolor == 79)										//승부 판결
				return 1;
			else
				return 2;
		}
		else if (arr[0][2] == arr[1][2] && arr[0][2] == arr[2][2]) {	//9 6 3 같을때
			flagcolor = &arr[0][2];										//해당라인 문자 확인후
			if (*flagcolor == 79)										//승부 판결
				return 1;
			else
				return 2;
		}
		else if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) {	//7 5 3 같을때
			flagcolor = &arr[0][0];										//해당라인 문자 확인후
			if (*flagcolor == 79)										//승부 판결
				return 1;
			else
				return 2;
		}
		else if (arr[2][0] == arr[1][1] && arr[2][0] == arr[0][2]) {	//9 5 1 같을때
			flagcolor = &arr[0][2];										//해당라인 문자 확인후
			if (*flagcolor == 79)										//승부 판결
				return 1;
			else
				return 2;
		}
		else if (turn == 9)												//9턴 까지 승부가 나지 않을경우.
			return 3;
		else															//그외 모든경우는 게임 재개
			return 0;
	};