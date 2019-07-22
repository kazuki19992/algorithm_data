// まとめ
// 2019/07/17
// u306065

#include<stdio.h>
#define SIZE 256

typedef struct{
    char character;     // a - yのいずれかの文字を格納
    int count;      // 出現回数をカウント
}initial;

void lin_search( char str[SIZE], initial data[25]);
void quick( initial data[25], int left, int right);
void swap( initial *a, initial *b);

int main(){
    initial data[25] = {{ 'a', 0},
                        { 'b', 0},
                        { 'c', 0},
                        { 'd', 0},
                        { 'e', 0},
                        { 'f', 0},
                        { 'g', 0},
                        { 'h', 0},
                        { 'i', 0},
                        { 'j', 0},
                        { 'k', 0},
                        { 'l', 0},
                        { 'm', 0},
                        { 'n', 0},
                        { 'o', 0},
                        { 'p', 0},
                        { 'q', 0},
                        { 'r', 0},
                        { 's', 0},
                        { 't', 0},
                        { 'u', 0},
                        { 'v', 0},
                        { 'w', 0},
                        { 'x', 0},
                        { 'y', 0}};

    char str[SIZE];
    int left = 0, right = 24;
    

    while(1){
        printf("英単語を入力してください :");
        scanf("%s",str);

        if(str[0] == 'z'){
            break;
        }

        lin_search(str, data);

    }


    quick(data, left, right);


    // 表示
    printf("出現回数順に出力します.\n");
    for( int i = 0; i < 25; i++){
        if( data[i].count != 0){
            printf("%c：%d回\n", data[i].character, data[i].count);
        }else{
            // break;
        }
    }
    return 0;
}

void lin_search(char str[SIZE], initial data[25]){
    for(int i = 0; i < 25; i++){
        if(str[0] == data[i].character){
            data[i].count++;
        }else{
            continue;
        }
    }
}

void quick( initial data[25], int left, int right){
    int pl, pr, pivot;

    pl = left;
    pr = right;
    pivot = data[ ( pl + pr) / 2].count;   // 基準値

    do{
        while( data[pl].count > pivot){
            pl++;                           // 右カーソル
        }
        while( data[pr].count < pivot){
            pr--;                           // 左カーソル
        }

        if( pl <= pr){
            swap( &data[pl], &data[pr]);
            pl++;
            pr--;
        }
    }while( pl <= pr);

    if( left < pr ){
        quick( data, left, pr);         // 再帰
    }
    if( right > pl){
        quick( data, pl, right);        // 再帰
    }
}

void swap( initial *a, initial *b){
    initial tmp = *a;
    *a = *b;
    *b = tmp;
}