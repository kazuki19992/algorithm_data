//ファイル処理
//2019/05/22 16:54
//u306065

#include<stdio.h>
#include<stdlib.h>

//学生情報用構造体
struct student{
  //学生番号
  int id;

  //氏名
  char name[32];
};

int main(){
  int i;
  FILE *fp;

  //学生情報
  struct student gakusei[3] = {
                              {306001,"sato"},
                              {306002,"suzuki"},
                              {306003,"tanaka"}};

  //ファイル書き込みモード
  fp = fopen("kadai1.txt","w");

  //学生情報書き込み
  for(i = 0;i < 3;i++){
    fprintf(fp,"学生番号:%d, 氏名:%s\n",gakusei[i].id,gakusei[i].name);
  }

  fclose(fp);

  return 0;
}
