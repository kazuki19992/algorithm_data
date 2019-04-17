//再帰処理・デバッグ
//2019/04/17 16:34
//u306065

#include <stdio.h>
#include <assert.h>

int sum(int n); //プロトタイプ宣言

int main(){
  int value;

  printf("正の偶数を入力して下さい:");
  scanf("%d",&value);
  printf("sum(%d) = %d\n",value,sum(value));

  return 0;
}

//引数nは正の偶数
int sum(int n){
  int ret;
  assert(n % 2 == 0 && n > 0);

  if(n == 2){
    return 2;
  }else{
    ret = sum(n - 2) + n;

    return ret;
  }
}

