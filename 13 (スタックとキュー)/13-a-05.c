// スタックとキュー(キュー)
// 2019/07/10
// u306065

#include<stdio.h>

#define QUEUE_SIZE 5    // キューの最大データ数
#define NO_DATA -1      // データなし

int queue[QUEUE_SIZE] = {NO_DATA};  // リングバッファ
int front = -1;                     // フロントカーソル
int rear = -1;                      // リアカーソル
int num = 0;                        // キューのデータ数

int EnQueue(int data);
int DeQueue();
void ShowQueue();

int main(){
    int select, data;

    for(int i = 0; i < QUEUE_SIZE; i++){
        queue[i] = NO_DATA;
    }

    while(1){
        printf("(1) Enqueue, (2) Dequeue, (0) Exit :");
        scanf("%d", &select);

        if(select == 0){
            return 0;
        }

        switch(select){
            case 1:{
                printf("Data? :");
                scanf("%d",&data);
                if(EnQueue(data) == -1){
                    printf("Enqueue is failed!\n");
                }
                ShowQueue();
                break;
            }
            case 2:{
                int temp = DeQueue();
                if(temp == -1){
                    printf("Dequeue is failed!\n");
                    continue;
                }else{
                    printf("Dequeue data is %d\n",temp);
                }
                ShowQueue();
                break;
            }
        }
    }
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
    if(rear >= QUEUE_SIZE){
        rear = 0;                   // リングバッファ
    }
    if( num >= QUEUE_SIZE){
        printf("Queue is Full!\n");
        rear = temp;
        return -1;
    }else{
        queue[rear] = data;
        num++;
        return 0;
    }
}

int DeQueue(){
    int temp, data = 0;
    temp = front;
    front++;
    if(front >= QUEUE_SIZE){
        front = 0;
    }
    if(num == 0){
        printf("Queue is Empty!\n");
        front = temp;
        return -1;
    }else{
        data = queue[front];
        queue[front] = NO_DATA;
        num--;
        return data;
    }
}