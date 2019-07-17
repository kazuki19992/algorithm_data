// まとめ
// 2019/07/17
// u306065

#include<stdio.h>

int fibonacci(int n);

int main(){
    int n;
    printf("n番目のフィボナッチ数を求めます。\nnの値は? :");
    scanf("%d",&n);
    printf("%d番目のフィボナッチ数は%dです\n",n,fibonacci(n));
    return 0;
}

int fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }else{
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
