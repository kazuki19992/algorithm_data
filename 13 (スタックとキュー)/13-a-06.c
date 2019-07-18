// スタックとキュー
// 2019/07/16
// 306065

#include<stdio.h>

#define SIZE 5
#define NO_DATA -1      // データなし

int queue[SIZE] = {NO_DATA};  // リングバッファ
int front = -1;                     // フロントカーソル
int rear = -1;                      // リアカーソル
int num = 0;                        // キューのデータ数

int EnQueue(int data);
int DeQueue();
void ShowQueue();

int stack[SIZE];  // スタックの実態の配列
int sp = -1;            // スタックポインタ(トップ)

int Push(int data);     // プッシュ
int Pop();              // ポップ
void ShowStack();       // スタック表示

int main() {
    int data,select;

    for(int i = 0; i < SIZE; i++){
        queue[i] = NO_DATA;
    }
    
    while(1){
        printf("(1) Push (2) Pop (3) Enq (4) Deq (5) Push(Deq) (6) Enq(Pop) (0) Exit :");
        scanf("%d",&select);

        switch(select){
            case 1: {       // Push
                printf("Data : ");
                scanf("%d",&data);      // Pushするデータの入力

                if(Push(data) == NO_DATA){
                    printf("Stack Overflow!\n");
                }else{
                    ShowStack();
                }
                break;
            }

            case 2: {       // Pop
                if(Pop() == NO_DATA){
                    printf("Stack Pop is failed!\n");
                }else{
                    ShowStack();
                }
                break;
            }

            case 3: {       // Enq
                printf("Data? :");
                scanf("%d",&data);
                if(EnQueue(data) == -1){
                    printf("Enqueue is failed!\n");
                }
                ShowQueue();
                break;
            }

            case 4:{        // Deq
                if(DeQueue() == -1){
                    printf("Dequeue is failed!\n");
                    continue;
                }
                ShowQueue();
                break;
            }

            case 5:{        // Push(Deq)
                int tmp = DeQueue();
                if(tmp == -1){
                    printf("Dequeue is failed!\n");
                    continue;
                }
                if(Push(tmp) == NO_DATA){
                    printf("Stack Overflow!\n");
                }else{
                    ShowQueue();
                    ShowStack();
                }
                break;
            }

            case 6:{        // Enq(Pop)
                int tmp = Pop();
                if(tmp == NO_DATA){
                    printf("Stack Pop is failed!\n");
                }
                if(EnQueue(tmp) == -1){
                    printf("Enqueue is failed!\n");
                }
                ShowStack();
                ShowQueue();
                break;
            }

            case 0: {       // 終了
                return 0;   
            }
        }
    }
}

void ShowQueue(){
    printf("Queue : ");
    for(int i = 0; i < SIZE; i++){
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
    if(rear >= SIZE){
        rear = 0;                   // リングバッファ
    }
    if( num >= SIZE){
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
    if(front >= SIZE){
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
        printf("Dequeue data is %d\n",data);
        return data;
    }
}

void ShowStack(){
    printf("Stack : ");
    for(int i = 0; i <= sp; i++){   // スタックポインタ(ボトムからトップまで表示)
        printf("[%d]",stack[i]);
    }
    putchar('\n');
}

int Push(int data){
    sp++;   // スタックポインタ +1
    if(sp >= SIZE){
        sp--;
        return -1;
    }else{
        stack[sp] = data;   // データ代入
        return 0;   // 正常終了
    }
}

int Pop() {
    int data = 0;   // データ初期化

    if(sp < 0){     // スタックポインタ確認
        printf("Stack Empty!\n");
        return -1;
    }else{
        data = stack[sp];   // スタック値を代入
        sp--;               // スタックポインタ -1
        printf("Pop data is %d\n",data);
        return data;        // 正常終了
    }
}