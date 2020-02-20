#include <stdio.h>
int main() {
  int x,n;
  int i=0;
  int count=0;
  scanf("%d %d",&x,&n);
  while(count<n){
    while(x<6){
      i=i+250;
      x++;
      count++;
      if(count>=n)break;

    }
    if(count>=n)break;
    else{
      count=count+8-x;
      x=1;
    }
  }
  printf("%d",i);
  return 0;
}
