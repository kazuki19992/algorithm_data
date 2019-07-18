// まとめ
// 2019/07/17
// u306065

#include<stdio.h>
#define SIZE 256

typedef struct{
    char character;     // a - yのいずれかの文字を格納
    int count = 0;      // 出現回数をカウント
}initial;

void lin_search(char str[SIZE], initial data[25]);


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
    

    while(1){
        printf("英単語を入力してください :");
        scanf("%s",str);

        if(str[0] == 'z'){
            break;
        }

        lin_search(str, data);

    }

    quick(



