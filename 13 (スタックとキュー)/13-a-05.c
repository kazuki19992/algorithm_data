// スタックとキュー(キュー)
// 2019/07/10
// u306065

#include<stdio.h>

#define QUEUE_SIZE 5    // キューの最大データ数
#define NO_DATA -1      // データなし

int queue[QUEUE_SIZE];  // リングバッファ
int front = -1;         // フロントカーソル
int rear = -1;          // リアカーソル
int num = 0;            // キューのデータ数

int EnQueue(int data);
int DeQueue();
void ShowQueue();

int main(){

}

void ShowQueue(){
    printf("Queue : ");
    for(int i = 0; i < QUEUE_SIZE; i++){
        if (queue[i] != NO_DATA){   // 有効データ
            printf("[%d]",queue[i]);
        }else{
            printf("[   ]");        // 無効データ
        }
    }
    putchar('\n');
}

int EnQueue(int data){
    int temp;
    temp = rear;
    rear++;
}