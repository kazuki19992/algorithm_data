//五目並べ
//2019/04/10 16:49
//u306065

#include <stdio.h>
void print_board(int board[3][3]); //プロトタイプ宣言

int main(void){
  int board[3][3] = {}; //0で初期化

  board[0][1] = 1;
  board[0][2] = 1;
  board[1][2] = -1;
  board[1][1] = -1;

  print_board(board);
  return 0;
}

void print_board(int board[3][3]){
  for(int i = 0;i < 3; i++ ){
    putchar('|');
    for(int j = 0;j < 3; j++ ){
      switch (board[i][j]){
        case -1:
          putchar('X');
          break;

        case 0:
          putchar(' ');
          break;

        case 1:
          putchar('O');
          break;
      }
      putchar('|');
    }
    putchar('\n');
  }
}
