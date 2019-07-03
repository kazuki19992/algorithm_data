//バブルソート・挿入ソート
//2019/05/29 17:30
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int data_bub[],int num);
void swap(int *a,int *b);
void quick(int data_q[],int left,int right);

int main(){
    int i,data_bub[80000],data_q[80000],data[80000];
    int num = 20;
    int left = 0,right;
    time_t start_b[5],start_q[5],end_b[5],end_q[5];
    
    srand(time(NULL));


    for(i = 0;i < 80000;i++){
        data[i] = rand();
    }

    i = 0;
    for(num = 5000; num <= 80000; num*=2,i++){
        right = num-1;

        //データのコピー
        for(int j = 0; j < num; j++){
            data_bub[j] = data[j];
            data_q[j] = data[j];
        }
        start_b[i] = clock();
        bubble(data_bub,num);
        end_b[i] = clock();

        start_q[i] = clock();
        quick(data_q,left,right);
        end_q[i] = clock();
    }

    //表示
    num = 5000;
    printf("<クイックソート法>\n");
    for( i = 0; i < 5; i++, num*=2){
        printf(" データ数：%d\n",num);
        printf(" 計算時間：%.3f秒\n",(float)(end_q[i]-start_q[i])/CLOCKS_PER_SEC);
        putchar('\n');
    }

    num = 5000;
    printf("<バブルソート法>\n");
    for( i = 0; i < 5; i++, num*=2){
        printf(" データ数：%d\n",num);
        printf(" 計算時間：%.3f秒\n",(float)(end_b[i]-start_b[i])/CLOCKS_PER_SEC);
        putchar('\n');
    }

    return 0;
}

void quick(int a[],int left,int right){
    int pl = left;
    int pr = right;
    int pivot; 

    pivot = a[(pl + pr) / 2];

    do{
        while(a[pl] < pivot){
            pl++;
        }
        while(a[pr] > pivot){
            pr--;
        }
        if(pl <= pr){
            swap( &a[pl],&a[pr] );
            pl++;
            pr--;
        }
    }while( pl <= pr);

    if( left < pr ){
        quick(a,left,pr);
    }
    if( pl < right ){
        quick(a,pl,right);
    }
}

void bubble(int data_bub[],int num){
    int i,j;
    for(i = 0;i < num-1;i++){
        for(j = num-1;j > i;j--){
            if(data_bub[j-1] > data_bub[j]){
                swap(&data_bub[j-1],&data_bub[j]);
            }
        }
    } 
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
        
