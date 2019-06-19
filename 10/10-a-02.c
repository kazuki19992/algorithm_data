//二分探索
//2019/06/19 17:00
//u306065
#include <stdio.h>
#define NUM 10

void insertion(int a[],int n);
int bin_search(int a[],int n,int key);

int main(){
    int i,ky,idx;
    int x[NUM];

    printf("Input integer number %d times \n",NUM);

    for(i = 0; i < NUM; i++){
        printf("x[%d]:",i);
        scanf("%d",&x[i]);
    }

    insertion(x,NUM);
    
    printf("\nデータ一時表示\n");
    for(i = 0; i < NUM; i++){
        printf("%d  ",x[i]);
    }
    putchar('\n');

    printf("Number to search:");
    scanf("%d",&ky);

    idx = bin_search(x,NUM,ky);

    if(idx == -1){
        printf("Searching was failed!\n");
    }else{
        printf("%d is located at %d \n",ky,idx);
    }

    return 0;
}

void insertion(int a[],int n){
    int i,j,tmp;
    for(i = 1;i <= n-1;i++){
        tmp = a[i];
        j = i;
        while((a[j-1]>tmp) && (j>0)) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = tmp;
    }
}

int bin_search(int a[],int n,int key){
    int pl = 0,pr = NUM - 1,pc;

    do {
        pc = ( pl + pr) / 2;
        if ( a[pc] == key){
            return pc;
        }else if(a[pc] < key){
            pl = pc+1;
        }else{
            pr = pc-1;
        }
    } while(pl <= pr);
    
    return -1;
}




















