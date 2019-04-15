//五目並べ
//2019/04/15 15:57
//u306065

#include <stdio.h>
#include <stdlib.h>

void mark_board(int board[15][15], int turn);
int judge(int board[15][15]);
void print_message(int result, int cnt);
void print_board(int board[15][15]); //プロトタイプ宣言

int main(void) {
	int board[15][15] = { 0 }; //0で初期化
	int turn = 1, result;
	int cnt = 1;//ゲームカウント変数

	print_board(board);
	for (int i = 0; i < 225; i++) { //最大試行回数が225のため

		mark_board(board, turn);
		print_board(board);
		result = judge(board);

		print_message(result, cnt);

		if (turn == 1) {
			turn = -1;
		}
		else {
			turn = 1;
		}

		cnt++;

	}

	return 0;
}

void mark_board(int board[15][15], int turn) {
	int row, columm;//row:行 , columm:列

	while (1) {
		if (turn == 1) {
			printf("先手の番です\n");
		}
		else {
			printf("後手の番です\n");
		}

		printf("縦位置は？");
		scanf_s("%d", &row);

		printf("横位置は？");
		scanf_s("%d", &columm);

		if (board[row][columm] == 0) { //既に石が設定されてないか確認する
			board[row][columm] = turn;
			break;
		}
		printf("そこには置けません\n");
	}
}

void print_board(int board[15][15]) {

	putchar(' ');
	for (int i = 0; i < 15; i++) {
		printf("%d", i % 10); //列番号
	}
	putchar('\n');
	for (int i = 0; i < 15; i++) {
		printf("%d", i % 10); //行番号
		for (int j = 0; j < 15; j++) {
			switch (board[i][j]) {
			case -1:
				putchar('x');
				break;

			case 0:
				putchar(' ');
				break;

			case 1:
				putchar('o');
				break;
			}
		}
		putchar('\n');
	}
}

int judge(int board[15][15]) {
	int flug = 0; //勝敗を記録
	int zeroFlg = 0; //ゼロ発見用



	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if ((board[i][j] == 1 && board[i][j + 1] == 1 && board[i][j + 2] == 1 && board[i][j + 3] == 1 && board[i][j + 4] == 1) || (board[i][j] == 1 && board[i + 1][j] == 1 && board[i + 2][j] == 1 && board[i + 3][j] == 1 && board[i + 4][j] == 1) || (board[i][j] == 1 && board[i + 1][j + 1] == 1 && board[i + 2][j + 2] == 1 && board[i + 3][j + 3] == 1 && board[i + 4][j + 4] == 1)) {
				flug = 1;
				break;
			}
			else if ((board[i][j] == -1 && board[i][j + 1] == -1 && board[i][j + 2] == -1 && board[i][j + 3] == -1 && board[i][j + 4] == -1) || (board[i][j] == -1 && board[i + 1][j] == -1 && board[i + 2][j] == -1 && board[i + 3][j] == -1 && board[i + 4][j] == -1) || (board[i][j] == -1 && board[i + 1][j + 1] == -1 && board[i + 2][j + 2] == -1 && board[i + 3][j + 3] == -1 && board[i + 4][j + 4] == -1)) {
				flug = -1;
				break;
			}
		}
	}
	for (int i = 14; i >= 0; i--) {
		for (int j = 0; j < 15; j++) {
			if (board[i][j] == 1 && board[i - 1][j + 1] == 1 && board[i - 2][j + 2] == 1 && board[i - 3][j + 3] == 1 && board[i - 4][j + 4] == 1) {
				flug = 1;
				break;
			}
			else if (board[i][j] == -1 && board[i - 1][j + 1] == -1 && board[i - 2][j + 2] == -1 && board[i - 3][j + 3] == -1 && board[i - 4][j + 4] == -1) {
				flug = -1;
				break;
			}
		}
	}
	
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {

			if (board[i][j] == 0) {
				zeroFlg = 1; //ゼロが見つかった場合に1にする
			}

		}
	}

	if (flug == 0 && zeroFlg == 0) {
		flug = -2;
	}

	return flug;
}

void print_message(int result, int cnt) {
	if (result == 1) {
		printf("Oの勝ちです\n");
		exit(0);
	}
	else if (result == -1) {
		printf("Xの勝ちです\n");
		exit(0);
	}
	else if (cnt == 225) {
		printf("引き分けです\n");
		exit(0);
	}
}