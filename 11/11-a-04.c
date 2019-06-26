//リスト
//2019/06/26
#include<stdio.h>
#define SIZE 20
typedef struct{
    int IntData;
    int NextIndex;
}MyList;

void ShowList(MyList data[]);

int main(){
    MyList LIST[SIZE] = {
        {1, 3},
        {9, 2},
        {4, 5},
        {3, 4},
        {5, 1},
        {15, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
        {-1, -1},
    };

    ShowList(LIST);
    return 0;
}

void ShowList(MyList data[]){
    int i = 0;
    printf("リスト：");
    while(1){
        //データの表示
        printf("%4d",data[i].IntData);

        //場所を更新
        i = data[i].NextIndex;

        //末尾に到達
        if(i == -1){
            break;
        }
    }
    putchar('\n');
}