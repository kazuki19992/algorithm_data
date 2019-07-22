// まとめ
#include<stdio.h>
#define data_ data[res]

typedef struct{
    int id;
    char name[50];
    int jpn, math, eng;
}student;

int bin_search(student data[], int key, int num);

int main(){
    student data[]={
        { 6101, "Erika", 98, 76, 85},
        { 6102, "Fumiyasu", 47, 88, 91},
        { 6103, "Rika", 56, 90, 78},
        { 6104, "Shoya", 65, 76, 83},
        { 6105, "Sho", 79, 73, 82},
        { 6106, "Tatsuya", 89, 48, 90},
        { 6107, "Kazunori", 68, 77, 85},
        { 6108, "Katsuhiro", 91, 65, 59},
        { 6109, "Tomohiro", 79, 62, 89},
        { 6110, "Masato", 85, 88, 79},
    };
    int num = 10;
    int key;

    printf("学生番号を入力してください :");
    scanf("%d",&key);

    int res = bin_search(data, key, num);
    int sum = data_.jpn + data_.math + data_.eng;
    
    if(res != -1){
        printf("%sさん(%4d)の成績は, 国語 %d点, 数学 %d点, 英語 %d点, 合計%d点です.\n", data_.name, data_.id, data_.jpn, data_.math, data_.eng, sum);
    }else{
        printf("その番号の学生は存在しません\n");
    }

    return 0;
}

int bin_search(student data[], int key, int num){
    int pl, pr, pc;

    // 初期化
    pl = 0, pr = num-1;

    do{
        pc = (pl + pr) / 2;
        if(data[pc].id == key){
            return pc;
        }else if(data[pc].id < key){
            pl = pc + 1;
        }else{
            pr = pc - 1;
        }
    } while(pl <= pr);

    return -1;
}