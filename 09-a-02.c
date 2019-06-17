//バブルソート・挿入ソート
//2019/05/29 17:30
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>
#include<time.h>

void bubble(int data_bub[],int num);
void swap(int *a,int *b);
void quick(int data_q[],int left,int right);
int comp_bub = 0,comp_q = 0,swap_bub = 0, swap_q = 0, n_insert = 0;

int main(){
    int i,data_bub[100],data_q[100];
    int num;
    int left = 0,right;
    
    srand(time(NULL));

    printf("num:");
    scanf("%d",&num);
    right = num-1;

    assert(num > 0 && num <= 100);

    printf("\n-----乱数生成値-----\n");
    for(i = 0;i < num;i++){
        data_bub[i] = rand();
        data_ins[i] = data_bub[i];
        printf("data[%d]:%d\n",i,data_bub[i]);

        //演出のために10ミリ秒のsleep関数を加える
        usleep(10000);
    }

    putchar('\n');

    printf("整列後データ (data_bub): \n");
    //演出のために1秒sleep
    sleep(1);

    bubble(data_bub,num);
    insertion(data_q,num);

    for(i = 0;i < num;i++){
        printf("%4d\n",data_bub[i]);
    }
    printf("\nn_comp:%d\nn_exchange:%d\n",n_comp_bub,n_exchange);
  
    printf("\n------------------------------\n\n");

    printf("整列後データ (data_ins): \n");
  
    //演出のために1秒sleep
    sleep(1);

    for(i = 0;i < num;i++){
        printf("%4d\n",data_ins[i]);
    }
    printf("\nn_comp:%d\nn_shift:%d\nn_insert:%d\n",n_comp_ins,n_shift,n_insert);
    return 0;
}

void insertion(int data_ins[],int num){
    int i,j,tmp;
    for(i = 1;i <= num-1;i++){
        tmp = data_ins[i];
        j = i;
        while((data_ins[j-1]>tmp) && (j>0)) {
            data_ins[j] = data_ins[j-1];
            j--;
            n_comp_ins += 2;
            n_shift ++;
        }
        data_ins[j] = tmp;
        n_comp_ins +=2;
        n_insert ++;
    }
}

void bubble(int data_bub[],int num){
    int i,j;
    for(i = 0;i < num-1;i++){
        for(j = num-1;j > i;j--){
            if(data_bub[j-1] > data_bub[j]){
                n_comp_bub++;
                swap(&data_bub[j-1],&data_bub[j]);
                n_exchange++;
            }else{
                n_comp_bub++;
            }
        }
    } 
}

void swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
        
