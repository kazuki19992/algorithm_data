//ファイル処理
//2019/05/22 17:29
//u306065

#include<stdio.h>
#include<stdlib.h>

int main(){
  int y,m,d;
  FILE *fp;
  double weight,height;
  char fname[30],lname[30];
  int today[3]={2019,5,22};
  int old = 0;

  //ファイル読み込みモード
  fp = fopen("kadai2.txt","r");

  //学生情報読み込み
  fscanf(fp,"%d %d %d %lf %lf %s %s", &y, &m, &d, &height, &weight, fname, lname);

  //年齢の計算
  if(m < today[1]){
    old = today[0] - y;
  }else if(m > today[1]){
    old = today[0] - y - 1;
  }else if(m == today[1]){
    if(d <= today[2]){
      old = today[0] - y;
    }else{
      old = today[0] - y + 1;
    }
  }

  //出力
  printf("氏名は %s %s です\n",fname,lname);
  printf("生年月日は %d年 %d月 %d日です (%d歳)\n",y,m,d,old);
  printf("身長は %.1lf cm 体重は %.1lf kgです\n",height,weight);

  
  fclose(fp);

  return 0;
}
