//五目並べ(応用)
//2019/04/13 0:16
//u306065

#include <stdio.h>
#include <stdlib.h>

void mark_board(int board[15][15], int turn);
int judge(int board[15][15]);
void print_message(int result);
void print_board(int board[15][15]); //プロトタイプ宣言

int main(void){
    int board[15][15] = {}; //0で初期化
    int turn = 1, result;

    while (1){ //処理の回数は最大9回ではあるが、問題により無限ループと定められているため
        mark_board(board, turn);
        print_board(board);
        result = judge(board);

        print_message(result);

        if (turn == 1){
            turn = -1;
        }else{
            turn = 1;
        }
    }

    return 0;
}

void mark_board(int board[15][15], int turn){
    int row, columm; //row:行 , columm:列

    while (1){
        if (turn == 1){
            putchar('O');
        }else{
            putchar('X');
        }
        printf("のターンです\n");

        printf("縦位置は？");
        scanf("%d", &row);

        printf("横位置は？");
        scanf("%d", &columm);

        if (board[row][columm] == 0){ //既に石が設定されてないか確認する
            board[row][columm] = turn;
            break;
        }
        printf("その座標に新規に設定することはできません。\n");
    }
}

void print_board(int board[15][15]){
    for (int i = 0; i <= 15; i++){

        if (i > 0){
            int row = i;
            if (row >= 10){
                row -= 10;
            }
            printf("%d", row);
        }

        for (int j = 0; j < 15; j++){
            if (i == 0){
                int columm = j;
                if(columm >= 10){
                    columm -= 10;
                }
                printf("%d", columm);
                putchar('\n');
            }else{
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
            }
        }
        putchar('\n');
    }
}

int judge(int board[15][15]){
    int flug = 0;    //勝敗を記録
    int tmp[15];     //結果一時保存用
    int zeroFlg = 0; //ゼロ発見用

    for (int select = 0; select < 4; select++){ //ルート探索

        switch (select){

        case 0: //横探索
            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    tmp[j] = board[i][j];
                }
                if (tmp[0] == tmp[1] && tmp[1] == tmp[2]){
                    flug = tmp[0];
                    break;
                }
            }
            break;

        case 1: //縦探索
            for (int i = 0; i < 15; i++){
                for (int j = 0; j < 15; j++){
                    tmp[j] = board[j][i];
                }
                if (tmp[0] == tmp[1] && tmp[1] == tmp[2]){
                    flug = tmp[0];
                    break;
                }
            }
            break;

        case 2: //斜め探索1
            for (int i = 0; i < 15; i++){
                tmp[i] = board[i][i];
            }
            if (tmp[0] == tmp[1] && tmp[1] == tmp[2]){
                flug = tmp[0];
                break;
            }
            break;

        case 3: //斜め探索2
            for (int i = 0; i < 15; i++){
                tmp[i] = board[i][15 - (i + 1)];
            }
            if (tmp[0] == tmp[1] && tmp[1] == tmp[2]){
                flug = tmp[0];
                break;
            }
            break;
        }
    }

    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){

            if (board[i][j] == 0){
                zeroFlg = 1; //ゼロが見つかった場合に1にする
            }
        }
    }

    if (flug == 0 && zeroFlg == 0){
        flug = -2;
    }

    return flug;
}

void print_message(int result){
    if (result == 1){
        printf("Oの勝ちです\n");
        exit(0);
    }
    else if (result == -1){
        printf("Xの勝ちです\n");
        exit(0);
    }
}