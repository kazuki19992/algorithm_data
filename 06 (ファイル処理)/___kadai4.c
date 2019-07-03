//306062　川村怜央
#include<stdio.h>
#include<stdlib.h>
#include"bmp.h"

//読み込み可能縦横サイズ
#define MAX_SIZE 256

int main(void){
  FILE *fp_in,*fp_out;
  int x,y;
  int width,height;//画像の縦横サイズ
  char r[MAX_SIZE][MAX_SIZE];
  char g[MAX_SIZE][MAX_SIZE];
  char b[MAX_SIZE][MAX_SIZE]; 

  //バイナリモードでファイルを開く
  fp_in=fopen("N.bpm","rb");

  //ビットマップヘッダを読み込む
  readBMPHeader(fp_in,&height,&width);

  //画像データの読み込み
  for(y=0;y<height;y++){
    for(x=0;x<width;x++){
      fread(&b[y][x],sizeof(b[y][x]),1,fp_in);
      fread(&g[y][x],sizeof(g[y][x]),1,fp_in);
      fread(&r[y][x],sizeof(r[y][x]),1,fp_in);
    }
  }

  //画像データの加工（黒い部分を赤くする）
  for(y=0;y<height;y++){
    for(x=0;x<width;x++){
      if(b[y][x]==0&&g[y][x]==0&&r[y][x]==0){
	b[y][x]=0;
	g[y][x]=0;
	r[y][x]=255;
      }
    }
  }
  //バイナリモードで書き込むファイルを開く
  fp_out=fopen("red.bpm","wb");

  //ビットマップヘッダの書き込み
  writeBMPHeader(fp_out,height,width);

  //画像データの書き込み
  for(y=0;y<height;y++){
    for(x=0;x<width;x++){
      fwrite(&b[y][x],sizeof(b[y][x]),1,fp_out);
      fwrite(&g[y][x],sizeof(g[y][x]),1,fp_out);
      fwrite(&r[y][x],sizeof(r[y][x]),1,fp_out);
    }
  }

  //ファイルを閉じる
  fclose(fp_in);
  fclose(fp_out);

  return 0;
}
