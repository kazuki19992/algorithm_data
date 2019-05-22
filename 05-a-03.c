// //構造体
// //2019/05/15 17:34
// //u306065
#include<stdio.h>
#include<math.h>

struct data{
//   double pts[3][2];

  double x;
  double y;
};
double calc(struct data pts[3]);

int main(){
  struct data pts[3];
  int px,py;

  //入力
  for(int i = 0;i < 3;i++){
    printf("P%dのX座標:",i);
    scanf("%d",&px);
<<<<<<< HEAD
    printf("    Y座標:");
=======
    printf("     Y座標:");
>>>>>>> 4589bec22451cbdeffadf6e52f4c2d3b64e981e4
    scanf("%d",&py);
    pts[i].x=px;
    pts[i].y=py;
  }

  // int res = calc(pts);
  double res = calc(pts);
  if(res == -1){
    printf("計算不能\n");
  }else{
    printf("\n Distance is %lf\n",res);
  }
  return 0;
}

double calc(struct data pts[3]){
  double x,y,z,tmp;
  
  //三角形の成立条件
  // for(int i=0;i<3;i++){
  //   if(i<2){
  //     tmp = (pts[i+1].x-pts[i].x)*(pts[i+1].x-pts[i].x)+(pts[i+1].y-pts[i].y)*(pts[i+1].y-pts[i].y);
  //     printf("ptslen[%d]=%lf\n",i,tmp);
  //     ptslen[i] = sqrt(tmp);
  //   }else if(i==2){
  //     tmp = (pts[i].x-pts[0].x)*(pts[i].x-pts[0].x)+(pts[i].y-pts[0].y)*(pts[i].y-pts[0].y);
  //     printf("ptslen[%d]=%lf\n",i,tmp);
  //     ptslen[i] = sqrt(tmp);
  //   }
  // }

  x = sqrt((pts[1].x-pts[0].x)*(pts[1].x-pts[0].x)+(pts[1].y-pts[0].y)*(pts[1].y-pts[0].y));
  y = sqrt((pts[2].x-pts[1].x)*(pts[2].x-pts[1].x)+(pts[2].y-pts[1].y)*(pts[2].y-pts[1].y));
  z = sqrt((pts[0].x-pts[2].x)*(pts[0].x-pts[2].x)+(pts[0].y-pts[2].y)*(pts[0].y-pts[2].y));

  if( x + y > z && y + z > x && x + z > y ){
    tmp = x + y + z;
<<<<<<< HEAD
    return tmp;
=======
    return sqrt(tmp);
>>>>>>> 4589bec22451cbdeffadf6e52f4c2d3b64e981e4
  }else{
    return -1;
  }

}
  

  
