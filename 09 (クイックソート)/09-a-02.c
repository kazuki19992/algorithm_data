//バブルソート・挿入ソート
//2019/05/29 17:30
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int data_bub[],int num);
void swap(int *a,int *b);
void quick(int data_q[],int left,int right,int num);
int comp_bub[5] = {0}, comp_q[5] = {0}, swap_bub[5] = {0}, swap_q[5] = {0};

int main(){
    int i,data_bub[100],data_q[100],data[100];
    int num = 20;
    int left = 0,right;
    
    srand(time(NULL));

    

    for(i = 0;i < 100;i++){
        data[i] = rand();
    }

    for(num = 20; num <= 100; num+=20){
        right = num-1;

        //データのコピー
        for(i = 0; i < num; i++){
            data_bub[i] = data[i];
            data_q[i] = data[i];
        }

        bubble(data_bub,num);
        quick(data_q,left,right,num);        
    }

    //表示
    num = 20;
    printf("<クイックソート法>\n");
    for( i = 0; i < 5; i++, num+=20){
        printf(" データ数：%d\n",num);
        printf(" 比較回数：%d回\n",comp_q[i]);
        printf(" 交換回数：%d回\n",swap_q[i]);
        putchar('\n');
    }

    num = 20;
    printf("<バブルソート法>\n");
    for( i = 0; i < 5; i++, num+=20){
        printf(" データ数：%d\n",num);
        printf(" 比較回数：%d回\n",comp_bub[i]);
        printf(" 交換回数：%d回\n",swap_bub[i]);
        putchar('\n');
    }

    return 0;
}

void quick(int a[],int left,int right,int num){
    int pl = left;
    int pr = right;
    int pivot; 

    pivot = a[(pl + pr) / 2];

    do{
        while(a[pl] < pivot){
            comp_q[(num/20)-1]++;
            pl++;
        }
        while(a[pr] > pivot){
            comp_q[(num/20)-1]++;
            pr--;
        }
        if(pl <= pr){
            swap( &a[pl],&a[pr] );
            swap_q[(num/20)-1]++;
            pl++;
            pr--;
        }
        comp_q[(num/20)-1]++;
    }while( pl <= pr);

    if( left < pr ){
        quick(a,left,pr,num);
    }
    if( pl < right ){
        quick(a,pl,right,num);
    }
}

void bubble(int data_bub[],int num){
    int i,j;
    for(i = 0;i < num-1;i++){
        for(j = num-1;j > i;j--){
            if(data_bub[j-1] > data_bub[j]){
                comp_bub[(num/20)-1]++;
                swap(&data_bub[j-1],&data_bub[j]);
                swap_bub[(num/20)-1]++;
            }else{
                comp_bub[(num/20)-1]++;
            }
        }
    } 
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
        
