//演習課題4

#include<stdio.h>
#include<stdlib.h>
#include "bmp.h"

#define MAX_SIZE 256

int main(){
  FILE *fp_in. *fp_out;
  int x,y;
  int width, height;
  char r[MAX_SIZE][MAX_SIZE];
  char g[MAX_SIZE][MAX_SIZE];
  char b[MAX_SIZE][MAX_SIZE];

  fp_in = fopen("N.bmp","rb");

  readBMPHeader(fp_in, &height, &width);

  for( y = 0; y < height; y++){
    for( x = 0; x < width; x++){
      fread(&b[y][x],sizeof(b[y][x]),1,fp_in);
      fread(&g[y][x],sizeof(g[y][x]),1,fp_in);
      fread(&r[y][x],sizeof(r[y][x]),1,fp_in);
    }
  }

  for( y = 0; y < height; y++){
    for( x = 0; x < width; x++){
      if(r[y][x] == 0 && g[y][x] == 0 && b[y][x] == 0){
        r[y][x] = (MAX_SIZE -1);
      }
    }
  }

  fp_out = fopen("red.bmp","wb");

  writeBMPHeader(fp_out,height,width);

  for( y = 0; y < height; y++){
    for( x = 0; x < width; x++){
      fwrite(&b[y][x],sizeof(b[y][x]),1,fp_in);
      fwrite(&g[y][x],sizeof(g[y][x]),1,fp_in);
      fwrite(&r[y][x],sizeof(r[y][x]),1,fp_in);
    }
  }

  fclose(fp_in);
  fclose(fp_out);

  return 0;
}
