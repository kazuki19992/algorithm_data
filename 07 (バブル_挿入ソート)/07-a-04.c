//バブルソート・挿入ソート
//2019/06/03 21:18
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>

struct DATA{
    char name[20];
    float height;
    float weight;
};

struct DATA students[10] = {
    {"阿部", 178.5, 72.4},
    {"佐藤", 168.8, 55.5},
    {"鈴木", 163.5, 82.3},
    {"高橋", 185.0, 76.5},
    {"田中", 175.1, 64.2},
    {"友近", 172.3, 68.2},
    {"中島", 179.7, 77.1},
    {"原田", 182.1, 69.3},
    {"安田", 174.5, 58.8},
    {"渡辺", 176.3, 65.6}
};

void insertion();

int main(){

    printf("-----元データ-----\n");
    for(int i = 0; i < 10; i++){
        printf("%2d | Name   : %s\n",i+1,students[i].name);
        printf("   | height : %.1f\n",students[i].height);
        printf("   | weight : %.1f\n",students[i].weight);
        printf("---+---------------------\n");
    }

    putchar('\n');
    insertion();

    printf("-----ソート後データ-----\n");
    for(int i = 0; i < 10; i++){
        printf("%2d | Name   : %s\n",i+1,students[i].name);
        printf("   | height : %.1f\n",students[i].height);
        printf("   | weight : %.1f\n",students[i].weight);
        printf("---+---------------------\n");
    }
    return 0;
}

void insertion(){
    int j;
    char tmp_n[20];
    float tmp_h,tmp_w;
    for(int i = 1; i < 10; i++){
        tmp_h = students[i].height;
        memcpy(tmp_n,students[i].name,sizeof(tmp_n)); //nameをコピーする
        tmp_w = students[i].weight;

        j = i;
        while((students[j-1].height > tmp_h) && (j > 0)){
            students[j] = students[j-1];
            j--;
        }
        students[j].height = tmp_h;
        memcpy(students[j].name, tmp_n, sizeof(students[j].name));
        students[j].weight = tmp_w;

    }
}