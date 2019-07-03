//リスト構造(配列)
//2019/06/26
#include<stdio.h>
#define SIZE 10
void ShowList(int data[]);
int main(){
    int list[SIZE] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, -1};
    ShowList(list);
    return 0;
}

void ShowList(int data[]){
    printf("リスト:");
    for(int i = 0; i < SIZE; i++){
        if( data[i] != -1){
            printf("%4d",data[i]);
        }else{
            break;
        }
    }
    putchar('\n');
}
