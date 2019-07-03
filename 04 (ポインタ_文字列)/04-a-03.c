//ポインタ・文字列
//2019/05/08 17:00
//u306065

#include<stdio.h>
#include<stdlib.h>
int main(){
  int i;
  char name[] = "Nihon University";
  char *p;
  char *str;
  int num = 0; //スペース記号の位置を特定

  //スペース記号の位置を調べる
  p = name;
  while(*p != '\0'){
    num++;
    if( *p == ' '){
      printf("%d文字目に見つかりました！\n",num);
      break;
    }
    p += 1;
  }

  //スペース記号の左側を保存する領域を確保(文字列+'\0'の領域)
  str = (char*)malloc(num* sizeof(char));

  //スペース記号の左側の文字列をmallocで確保した領域にコピー
  for(i=0;i<num;i++){
    str[i] = name[i];
  }
  str[i+1]='\0'; //終端記号

  //スペース記号の左側の文字列を画面に表示
  printf("%s\n",str);

  //mallocで確保した領域の解放
  free(str);

  return 0;
}
