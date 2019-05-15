//構造体
//2019/05/15 17:34
//u306065
#include<stdio.h>
#include<math.h>
struct data{
  double pts[3][2];
};
bool judge(struct data);

int main(){
  struct data pts;
  bool judge;

  //入力
  for(int i = 0;i < 3;i++){
    printf("P%dのX座標:",i);
    scanf("%d",&data.pts[i][0]);
    printf("     Y座標:");
    scanf("%d",&data.pts[i][1]);
  }

  //判定
  if((judge(pts))==false){
    printf("計算不能\n");
  }

  
