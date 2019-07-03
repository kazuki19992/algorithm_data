//クイックソート(ちゃんと印字ver.)
//2019/06/12 16:33
//u306065

#include<stdio.h>

void quick(int a[],int left,int right);
void swap(int *pl, int *pr);

int pass = 0; //パス

int main(){
    int a[] = { 1, 7, 4, 6, 9, 8, 3, 5, 2, 10};
    int left = 0, right = 9;

    printf("<印字出力の形式>\n\n");
    quick(a,left,right);
    
    printf("\nソート終了：");
    for(int i=0;i < 9;i++){
        printf("%d  ",a[i]);
    }
    putchar('\n');

    return 0;
}

void quick(int a[],int left,int right){
    pass++;

    int pl = left;
    int pr = right;
    int pivot,tmpl,tmpr; 

    pivot = a[(pl + pr) / 2];
    
    printf("%d回目の呼び出し：\n",pass);
    printf("\t\t<開始時>\n");
    printf("\t\t 左端の添え字：%d\n",pl);
    printf("\t\t 右端の添え字：%d\n",pr);
    printf("\t\t ピボットの添え字：%d\n",(pl + pr)/2 );
    printf("\t\t ピボットの値    ：%d\n",pivot);
    printf("\t\t 左端〜右端の値：");
    
    for(int i = pl;i <= pr;i++){ printf("%d ",a[i]); }
    putchar('\n');

    tmpl = pl;
    tmpr = pr;

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
    
    printf("\t\t<ソーティング結果>\n");
    printf("\t\t 左端〜右端の値：");
    for(int i = tmpl;i <= tmpr;i++){ printf("%d ",a[i]); }
    putchar('\n');

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

