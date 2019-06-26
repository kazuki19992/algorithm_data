//リスト構造(配列)
// リスト構造って配列で作るんですねｗｗｗｗｗｗｗｗ
//2019/06/26
#include<stdio.h>
#include<assert.h>
#define SIZE 15
void ShowList(int data[]);
int InsertNode(int no, int insdata, int data[]);
int DeleteNode(int no, int data[]);
int main(){
    char select;
    int no,insdata,ins,del;
    int list[SIZE] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, -1, -1, -1, -1, -1, -1};

    while(1){

        ShowList(list);
        
        //モード選択
        printf("編集選択 (挿入 = i, 削除 = d, 編集終了 = q) :");
        // fflush(stdin);
        scanf(" %c",&select);
        assert(select == 'i' || select == 'd' || select == 'q');

        if(select == 'i'){
                printf("挿入位置：");
                // fflush(stdin);
                scanf("%d%*c",&no);
                printf("挿入データ：");
                // fflush(stdin);
                scanf("%d%*c",&insdata);

                ins = InsertNode(no,insdata,list);

                if(ins == 0){
                    printf("挿入成功\n");
                    continue;
                }else{
                    printf("挿入失敗\n");
                    continue;
                }
        }else if(select == 'd'){
                printf("削除位置：");
                scanf("%d",&no);
                
                del = DeleteNode(no,list);
                if(del == 0){
                    printf("削除成功\n");
                    continue;
                }else{
                    printf("削除失敗\n");
                    continue;
                }
        }else if(select == 'q'){
                return 0;
        }
    }
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

int InsertNode(int no,int insdata,int data[]){

    //データ数のカウント
    int n;
    for(n = 0; n < SIZE; n++){
        if( data[n] == -1){
            break;
        }
    }


    //配列がいっぱいの場合
    if( n == SIZE ){
        return -1;
    }else if( n < no ){ //挿入位置の左側にデータがない
        return -1;
    }else{
        //挿入可能
        for( int i = n-1; i >= no; i--){
            data[i + 1] = data[i];
        }
        data[no - 1] = insdata;
        return 0;
    }
}

int DeleteNode(int no, int data[]) {
    int n,i;

    //データ個数のカウント
    for(n = 0; n < SIZE; n++){
        if(data[n] == -1){
            break;
        }
    }

    //削除位置にデータの有無を確認
    if(no < 0 || n <= no-1){
        return -1;
    }else{
        //データの削除が可能

        //データを左に詰める
        for(i = no; i < n; i++){
            data[i - 1] = data[i];
        }

        //data[n-1]を無効にする
        data[n-1] = -1;

        //削除成功 -> 0を返す
        return 0;
    }
}