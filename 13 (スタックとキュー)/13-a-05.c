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
    tmp = rear;
    rear++;                         // リア +1
    if (rear >= QUEUE_SIZE){        // リングバッファ
        rear = 0;
    }
    if (num >= QUEUE_SIZE){         // 配列サイズ超過
        printf("Queue is Full!\n");
        rear = tmp;
        return -1;
    }else{
        queue[rear] = data;         
        num++;                      // データ数+1
        return 0;                   // 正常終了
    }
}

int DeQueue () {
    int tmp, data = 0;              // データ初期化
    tmp = front;
    front++;                        // フロント++

    if ( front >= QUEUE_SIZE){
        front = 0;                  // リングバッファ
    }
    if ( num == 0){
        
