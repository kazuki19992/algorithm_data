// スタックとキュー
// 2019/07/10
// u306065

#include<stdio.h>

#define STACK_SIZE 5    // スタックの最大データ数
#define NO_DATA -1      // データなし

int stack[STACK_SIZE];  // スタックの実態の配列
int sp = -1;            // スタックポインタ(トップ)

int Push(int data);     // プッシュ
int Pop();              // ポップ
void ShowStack();       // スタック表示

int main() {
    int data,select;
    
    while(1){
        printf("(1) Push (2) Pop (0) Exit :");
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

            case 0: {       // 終了
                return 0;   
            }
        }
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
    if(sp >= STACK_SIZE){
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
        return data;        // 正常終了
    }
}