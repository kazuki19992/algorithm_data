//ファイル処理
//2019/05/22 16:54
//u306065

#include<stdio.h>
#include<stdlib.h>

int main(){
  int y,m,d;
  FILE *fp;
  double weight,height;
  char fname[30],lname[30];

  //入力
  printf("誕生年:");
  scanf("%d",&y);
  
  printf("誕生月:");
  scanf("%d",&m);

  printf("誕生日:");
  scanf("%d",&d);

  printf("\n身長:");
  scanf("%lf",&height);

  printf("体重:");
  scanf("%lf",&weight);

  printf("\n名字:");
  scanf("%s",fname);

  printf("名前:");
  scanf("%s",lname);



  //ファイル書き込みモード
  fp = fopen("kadai2.txt","w");

  //学生情報書き込み
  fprintf(fp,"%d %d %d\n%lf %lf\n%s %s\n", y, m, d, height, weight, fname, lname);

  fclose(fp);

  return 0;
}
