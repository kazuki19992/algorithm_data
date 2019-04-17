//再帰関数・デバッグ
//2019/04/17 17:17
//u306065

#include<stdio.h>

int factorial(int n); //プロトタイプ宣言

int main(){
  int n,input;
  
  printf("自然数を入力して下さい:");
  scanf("%d",&input);
  
  n = factorial(input);
  
  printf("%dの階乗は%dです\n",input,n);
  return 0;
}

int factorial(int n){
  int tmp;

  printf("関数 Factorial(%d) にはいりました.\n",n);
  if(n == 0){
    tmp = 1;
  }else{
    tmp = n * factorial(n - 1);
  }

  printf("関数Factorial(%d)から出ます: Factorial(%d) = %d.\n",n,n,tmp);
  return tmp;
}
