#include<stdio.h>
// #include<string>
#define NUM 5

typedef struct{
    int id;
    char name[10];
    int score;
}student;

void swap(student *a, student *b);
void quick(student data[], int left, int right);

int main(){
    int i;

    student data[NUM] = {{101,"斎藤",76},
                         {103,"田中",53},
                         {100,"中野",81},
                         {102,"松本",93},
                         {104,"吉田",85}};
    
    printf("[ソート前]\n");
    printf("学生番号\t名前\t点数\n");
    for(i = 0; i < NUM; i++){
        printf("%d\t\t%s\t%d\n",data[i].id,data[i].name,data[i].score);
    }
    printf("\n");

    quick(data,0,NUM-1);

    printf("[ソート後]\n");
    printf("学生番号\t名前\t点数\n");
    for(i = 0; i < NUM; i++){
        printf("%d\t\t%s\t%d\n",data[i].id,data[i].name,data[i].score);
    }

    return 0;
}

void swap(student *a, student *b) {
    student tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick(student data[], int left, int right){
    int pl = left;
    int pr = right;
    int pivot = data[(pl + pr) / 2].score;

    do {
        while(data[pl].score > pivot) {
            pl++;
        }
        while(data[pr].score < pivot) {
            pr--;
        }
        if(pl <= pr){
            swap(&data[pl], &data[pr]);
            pl++;
            pr--;
        }
    } while(pl <= pr);

    if(left < pr){
        quick(data, left, pr);
    }
    if(pl < right) {
        quick(data, pl, right);
    }
}