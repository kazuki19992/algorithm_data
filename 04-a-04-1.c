//ポインタ・文字列
//2019/05/08 17:34
//u306065
//ポインタでやるやつ

#include<stdio.h>
#include<string.h>
#include<assert.h>

int main(){
  char str[16]; //(1)
  char *p_str; //(2)
  int i = 0,cnt = 0;
  int word_cnt[15] = {0};
  
  p_str=&str[0]; //アドレスを格納

  while(1){ //
    //入力部
    printf("%d番目の英単語を入力してください(15文字以内):\n-->  ",i + 1);
    // while(1){
    //   //入力・検査部
    //   scanf("%c",p_str + cnt);
    //   if(*(p_str + cnt)=='\0'){
    //     break;
    //   }
    //   cnt++;
    // }
    scanf("%s",p_str);

    //入力値検査
    if(*(p_str)=='*'){
      break;
    }

    //文字数カウント部
    for(cnt=0;*(p_str + cnt)!='\0';cnt++);

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
