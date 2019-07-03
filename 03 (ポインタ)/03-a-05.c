//ポインタ
//u306065
//2019/05/06 17:09

#include<stdio.h>
#include<assert.h>
#define MAXNUM 10
int main(){
    int nin;
    int data[MAXNUM],*pdata;
    int goukei;
    int i;

    
    scanf("%d",&nin); //nin → &nin
    assert(nin > 0); //想定値以外の入力を禁止
    for(i=0;i<nin;i++){
        scanf("%d",&data[i]);
        assert(data[i] >= 0 && data[i] <= 100); //想定値以外の入力を禁止
    }

    pdata = &data[0]; //*data → &data[0]

    for(i=0;i<nin;i++){
        *pdata++=*(data+i)+43;
    }

    pdata=&data[0];
    goukei=*pdata; //pdata → *pdata

    for(i=1;i<nin;i++){ //i=1 → i=0 // i<=nin → i<nin
        goukei += *( pdata + i );  //pdata → ( pdata + i )
    }
    printf("合計=%d\n",goukei);
    return(0);
}