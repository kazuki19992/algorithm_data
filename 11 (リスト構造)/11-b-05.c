//リスト
//2019/06/26
#include<stdio.h>
#define SIZE 20
typedef struct{
    int IntData;
    int NextIndex;
}MyList;

void ShowList(MyList data[]);
int InsertNode(int no, int insdata, MyList data[]);
int DeleteNode(int no, MyList data[]);
//ここまで変更 - ここからやる

int main(){
    int no,insdata,id;
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

    printf("挿入場所：");
    scanf("%d",&no);
    printf("挿入データ：");
    scanf("%d",&insdata);

    id = InsertNode(no,insdata,LIST);
    if(id == 0){
        printf("挿入成功\n");
    }else{
        printf("挿入失敗\n");
    }
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


int InsertNode(int index, int ins_data, MyList data[]){
    int blank = 0; //配列の空いている場所
    int n =0, i = 0, pre = -1;

    //空いている場所を探す
    for(blank = 0; blank < SIZE; blank++){
        if(data[blank].IntData == -1){
            break;
        }
    }

    //削除対象範囲外もしくは配列が満杯
    //挿入不可
    if(index <= 1 || blank == SIZE){
        return -1;
    }

    while(1){
        if(data[i].IntData != -1){
            n++; //挿入位置まで移動
            if(n == index){
                //データの挿入
                data[blank].IntData = ins_data;
                data[blank].NextIndex = data[pre].NextIndex;
                data[pre].NextIndex = blank;
                return 0;
            }
        }
        pre = i;
        i = data[i].NextIndex;

        //末尾到達 && 挿入位置に到達せず
        if(data[i].IntData == -1){
            return -1;
        }
    }
}