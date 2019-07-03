//ポインタ・文字列
//2019/05/08 17:34
//u306065

#include<stdio.h>
#include<string.h>
#include<assert.h>

int main(){
  char str[16]; //(1)
  //char *str; //(2)
  int i = 0,cnt;
  int word_cnt[15] = {0};
  
  while(1){ //
    //入力部
    printf("%d番目の英単語を入力してください(15文字以内):\n-->  ",i + 1);
    scanf("%s",str);

    //入力値検査
    if(str[0]=='*'){
      break;
    }

    //文字数カウント部
    for(cnt=1;str[cnt]!='\0';cnt++);

    //加算
    word_cnt[cnt-1]+=1;    
    
    i++;
  }

  //表示部
  printf("結果の表示法\n\n");
  printf("文字数    出現回数\n");
  for(int j = 0;j < 15;j++){
    printf("%2d        %2d\n",j+1,word_cnt[j]);
  }

  return 0;
}
