//バブルソート・挿入ソート
//2019/05/29 16:37
#define NUM 1000
#include<stdio.h>
void bubble(int x[NUM],int num);
void swap(int *a,int *b);
int n_comp = 0, n_exchange = 0;
int main(){
  int i,x[NUM];
  int num;

  printf("num:");
  scanf("%d",&num);

  for(i = 0;i < num;i++){
    printf("x[%d]:",i);
    scanf("%d",&x[i]);
  }

  bubble(x,num);

  printf("整列後データ : ");
  for(i = 0;i < num;i++){
    printf("%4d",x[i]);
  }
  printf("\nn_comp:%d\nn_exchange:%d\n",n_comp,n_exchange);
  return 0;
}

void bubble(int x[NUM],int num){
  int i,j;
  for(i = 0;i < num-1;i++){
    for(j = num-1;j > i;j--){
      if(x[j-1] > x[j]){
        n_comp++;
        swap(&x[j-1],&x[j]);
        n_exchange++;
      }else{
        n_comp++;
      }
    }
  }
}

void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
