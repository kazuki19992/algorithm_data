//演習課題4

#include<stdio.h>
#include<stdlib.h>
#include "bmp.h"

//読み込み可能な縦横サイズ
#define MAX_SIZE 256

int main(){
  FILE *fp_in, *fp_out;
  int x,y;
  int width, height; //画像の縦横サイズ
  char r[MAX_SIZE][MAX_SIZE];
  char g[MAX_SIZE][MAX_SIZE];
  char b[MAX_SIZE][MAX_SIZE];

  //バイナリモードでファイルを開く
  fp_in = fopen("N.bmp","rb");

  //ビットマップヘッダを読み込む
  readBMPHeader(fp_in, &height, &width);

  //画像データの読み込み
  for( y = 0; y < height; y++){
    for( x = 0; x < width; x++){
      fread(&b[y][x],sizeof(b[y][x]),1,fp_in);
      fread(&g[y][x],sizeof(g[y][x]),1,fp_in);
      fread(&r[y][x],sizeof(r[y][x]),1,fp_in);
    }
  }

  //画像データの加工(黒い部分を赤く)
  for( y = 0; y < height; y++){
    for( x = 0; x < width; x++){
      if((r[y][x] == 0) && (g[y][x] == 0) && (b[y][x] == 0)){
        r[y][x] = 255; //(MAX_SIZE -1);
      }
    }
  }

  //バイナリモードで書き込むファイルを開く
  fp_out = fopen("red_M.bmp","wb");

  //ビットマップヘッダの書き込み
  writeBMPHeader(fp_out,height,width);

  //画像データの書き込み (ミラー)
  for( y = 0; y < height; y++){
    for( x = width-1; x >= 0; x--){
      fwrite(&b[y][x],sizeof(b[y][x]),1,fp_out);
      fwrite(&g[y][x],sizeof(g[y][x]),1,fp_out);
      fwrite(&r[y][x],sizeof(r[y][x]),1,fp_out);
    }
  }

  fclose(fp_in);
  fclose(fp_out);

  return 0;
}
