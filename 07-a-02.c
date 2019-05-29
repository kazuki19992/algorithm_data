//バブルソート・挿入ソート
//2019/05/29 16:37
#define NUM 1000
#include<stdio.h>
void insertion(int x[],int num);
int n_comp = 0, n_shift = 0, n_insert = 0;

#define count0 n_comp
#define count1 n_shift
#define count2 n_insert

int main(){
  int i,x[NUM];
  int num;

  printf("num:");
  scanf("%d",&num);

  for(i = 0;i < num;i++){
    printf("x[%d]:",i);
    scanf("%d",&x[i]);
  }

  insertion(x,num);

  printf("整列後データ : ");
  for(i = 0;i < num;i++){
    printf("%4d",x[i]);
  }
  printf("\nn_comp:%d\nn_shift:%d\nn_insert:%d\n",n_comp,n_shift,n_insert);
  return 0;
}

void insertion(int x[],int num){
  int i,j,tmp;
  for(i = 1;i <= num-1;i++){
    tmp = x[i];
    j = i;
    while((x[j-1]>tmp) && (j>0)) {
      x[j] = x[j-1];
      j--;
      count0 += 2;
      count1 ++;
    }
    x[j] = tmp;
    count0 +=2;
    count2 ++;
  }
}

