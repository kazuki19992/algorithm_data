//バブルソート・挿入ソート
//2019/05/29 17:30
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>

void bubble(int data_bub[],int num);
void swap(int *a,int *b);
void insertion(int data_ins[],int num);
int n_comp_bub = 0,n_comp_ins = 0,n_exchange = 0, n_shift = 0, n_insert = 0;

int main(){
  int i,data_bub[2000],data_ins[2000];
  int num;

  printf("num:");
  scanf("%d",&num);
  
  assert(num > 0 && num <= 2000);

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
  insertion(data_ins,num);

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
        
