//バブルソート・挿入ソート
//2019/05/29 17:30
#define NUM 100
#include<stdio.h>
#include<stdlib.h>

void bubble(int x[NUM],int num);
void swap(int *a,int *b);
void insertion(int x[],int num);
int n_comp_bub = 0,n_comp_ins = 0, n_shift = 0, n_insert = 0;

int main(){
  int i,data_bub[NUM],data_ins[NUM];
  int num;

  printf("num:");
  scanf("%d",&num);
  
  for(i = 0;i < num;i++){
    data_bub[i] = rand();
    data_ins[i] = data_bub[i];
    printf("x[%d]:%d",i,data_bub[i]);
    sleep(1);
  }

  bubble(x,num);
  insertion(x,num);

  printf("整列後データ (data_bub): ");
  for(i = 0;i < num;i++){
    printf("%4d",data_bub[i]);
  }
  printf("\nn_comp:%d\nn_exchange:%d\n",n_comp_bub,n_exchange);
  
  printf("\n------------------------------\n\n");

  printf("整列後データ (data_ins): ");
  for(i = 0;i < num;i++){
    printf("%4d",data_ins[i]);
  }
  printf("\nn_comp:%d\nn_shift:%d\nn_insert:%d\n",n_comp_ins,n_shift,n_insert);
  return 0;
}

void insertion(int data_ins[],int num){
  int i,j,tmp;
  for(i = 1;i <= num-1;i++){
    tmp = x[i];
    j = i;
    while((x[j-1]>tmp) && (j>0)) {
      x[j] = x[j-1];
      j--;
      n_comp_ins += 2;
      n_shift ++;
    }
    x[j] = tmp;
    n_comp_ins +=2;
    n_insert ++;
  }
}

void bubble(int data_bub[],int num){
  int i,j;
  for(i = 0;i < num-1;i++){
    for(j = num-1;j > i;j--){
      if(x[j-1] > x[j]){
        n_comp_bub++;
        swap(&x[j-1],&x[j]);
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
        
