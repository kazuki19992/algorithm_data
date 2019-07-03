//構造体
//2019/05/15 17:03
//u306065
#include <stdio.h>
struct students{
  int id;
  char *name;
  int pts[3];
  //int math;
  //int eng;
  //int jpn;
};

int main(){
  struct students data[]={
  {306001,"阿部",{82,72,90}},
  {306051,"佐藤",{68,50,62}},
  {306101,"鈴木",{42,65,52}},
  {306151,"高橋",{92,34,46}},
  {306201,"渡辺",{50,70,74}}};
  int sum=0,sub_sum[3]={0};
  
  printf("                   成績リスト\n");
  printf("学生番号\t氏名\t数学\t英語\t国語\t合計\n");
  
  //表示
  for(int i=0;i<5;i++){
    printf("%d\t\t%s\t",data[i].id,data[i].name);
    for(int j=0;j<3;j++){
      printf("%d\t",data[i].pts[j]);
      //合計
      sum+=data[i].pts[j];

      //教科毎の合計
      sub_sum[j]+=data[i].pts[j];
    }
    printf("%d\n",sum);
    sum = 0;
  }

  //平均点表示
  printf("平均点\t\t\t");
  for(int i=0;i<3;i++){
    printf("%.1f点\t",(float)sub_sum[i]/5);
  }
  putchar('\n');

  return 0;
}

