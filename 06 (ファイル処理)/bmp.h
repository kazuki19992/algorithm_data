#ifndef __BMP_H_
#define __BMP_H_

#define BIT_COUNT 24

// ビットマップファイルヘッダ
typedef struct tagBITMAPFILEHEADER {
  unsigned char bfType[2];
  unsigned char bfSize[4];
  unsigned char bfReserved1[2];
  unsigned char bfReserved2[2];
  unsigned char bfOffBits[4];
} BITMAPFILEHEADER;


// ビットマップ情報ヘッダ
typedef struct tagBITMAPINFOHEADER{
  unsigned char  biSize[4];
  unsigned char  biWidth[4];
  unsigned char  biHeight[4];
  unsigned char  biPlanes[2];
  unsigned char  biBitCount[2];
  unsigned char  biCompression[4];
  unsigned char  biSizeImage[4];
  unsigned char  biXPixPerMeter[4];
  unsigned char  biYPixPerMeter[4];
  unsigned char  biClrUsed[4];
  unsigned char  biClrImportant[4];
} BITMAPINFOHEADER;

// ビットマップの読み込み
void readBMPHeader(FILE* file, int* height, int* width);

// ビットマップヘッダの書き込み
void writeBMPHeader(FILE* fp, int height, int width);

#endif
