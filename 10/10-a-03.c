//二分探索
//2019/06/19 17:25
//u306065
#include <stdio.h>
#include <stdlib.h>
#define MAX 2000
#define FMAX 20

void swap(int *x, int *y);
void quick(int a[],int left,int right);
int bin_search(int a[],int n,int key);
int lin_search(int a[],int n,int key);

int main(){
    int i,left = 0,right;
    int seisu[MAX];
    int kosu,ky,idx0,idx1;
    char fname[FMAX];
    FILE *fp;

    kosu = MAX; //データ個数をkosuに代入

    printf("Input file name:");
    scanf("%s",fname);

    fp = fopen(fname,"r");

    if(fp==NULL){
        printf("No file found !\n");
        exit(1);
    }

    //データをkosu個読み込む
    printf("kosu:");
    scanf("%d",&kosu);

    for(i = 0; i < kosu; i++){
        fscanf(fp,"%d",&seisu[i]);
    }
    right = kosu - 1;
    
    printf("Number to search:");
    scanf("%d",&ky);

    idx0 = lin_search(seisu,kosu,ky);
    
    quick(seisu,left,right);

    idx1 = bin_search(seisu,kosu,ky);

    printf("\n計算回数表示\n");

    if(idx0 == -1){
        printf("Searching was failed!\n");
    }else{
        printf("lin:%d\nbin:%d \n",idx0,idx1);
    }

    fclose(fp);
    return 0;
}

void swap(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void quick(int a[],int left,int right){
    int pl = left;
    int pr = right;
    int pivot;
    pivot = a[(pl + pr) / 2];

    do {
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
    }while(pl <= pr);

    if( left < pr ){
        quick(a,left,pr);
    }
    if(pl < right ){
        quick(a,pl,right);
    }
}

int bin_search(int a[],int n,int key){
    int pl = 0,pr = MAX - 1,pc,cnt = 0;

    do {
        pc = ( pl + pr) / 2;
        cnt++;
        if ( a[pc] == key){
            return cnt;
        }else if(a[pc] < key){
            pl = pc+1;
        }else{
            pr = pc-1;
        }
    } while(pl <= pr);
    
    return -1;
}

int lin_search(int a[],int n,int key){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt++;
        if(a[i] == key){
            return cnt;
        }
    }
    return -1;
}


















