#include<stdio.h>
#define NUM 20

int binsearch(int a[], int n, int key);
int main(){
    int ky,idx;
    int x[] = {1, 2, 4, 5, 6, 7, 9, 10, 11, 13, 15, 16, 17, 18, 19, 20, 21, 22, 25, 29};

    printf("探索する値->");
    scanf("%d",&ky);

    idx = binsearch(x, NUM, ky);

    if(idx == -1){
        printf("\n探索失敗\n");
    }else{
        printf("\nインデックス->%d\n",idx);
    }

    return 0;
}

int binsearch(int a[], int n, int key){
    int pl = 0;
    int pr = n-1;
    int  pc;

    printf("中央のインデックス->");
    do {
        pc = (pl + pr) / 2;
        printf("%d  ",pc);
        if(a[pc] == key){
            return pc;
        }else if(a[pc] < key){
            pl = pc + 1;
        }else{
            pr = pc - 1;
        }
    } while(pl <= pr);

    return -1;
}