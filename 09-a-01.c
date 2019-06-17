//クイックソート
//2019/06/12 16:33
//u306065

#include<stdio.h>

void quick(int a[],int left,int right);
void swap(int *pl, int *pr);

int main(){
    int a[] = { 1, 7, 4, 6, 9, 8, 3, 5, 2, 10};
    int left = 0, right = 9;

    quick(a,left,right);
    
    for(int i=0;i < 9;i++){
        printf("%d  ",a[i]);
    }
    putchar('\n');

    return 0;
}

void quick(int a[],int left,int right){
    int pl = left;
    int pr = right;
    int pivot; 

    pivot = a[(pl + pr) / 2];

    do{
        while(a[pl] < pivot){
            pl++;
        }
        while(a[pr] > pivot){
            pr--;
        }
        if(pl <= pr){
            swap( &a[pl],&a[pr] );
            pl++;
            pr--;
        }
    }while( pl <= pr);

    if( left < pr ){
        quick(a,left,pr);
    }
    if( pl < right ){
        quick(a,pl,right);
    }
}

void swap(int *pl, int *pr){
    int tmp;
    tmp = *pr;
    *pr = *pl;
    *pl = tmp;
}

