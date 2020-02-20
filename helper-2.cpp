#include <stdio.h>
#include <math.h>

int main()
{
  int n=0;
  int pen1=0,price1=0;
  int pen2=0,price2=0;
  int pen3=0,price3=0;
  int c1=0,c2=0,c3=0;
  int t1=0,t2=0,t3=0;
  int min=1e8,min1=0;
  int a=0,b=0,c=0;
  scanf("%d",&n);
  scanf("%d %d",&pen1,&price1);
  scanf("%d %d",&pen2,&price2);
  scanf("%d %d",&pen3,&price3);
  a=n%pen1;
  b=n%pen2;
  c=n%pen3;
  if(a==0)
  c1=price1*n/pen1;
  else {
  t1=n/pen1+1;
  c1=t1*price1;}
  if(b==0)
  c2=price2*n/pen2;
  else {
      t2=n/pen2+1;
      c2=t2*price2;

  }
  if(c==0)
  c3=price3*n/pen3;
  else {
      t3=n/pen3+1;
      c3=t3*price3;
  }
  if(c1<c2&&c1<c3)
  min=c1;
  if(c2<c1&&c2<c3)
  min=c2;
  if(c3<c1&&c3<c2)
  min=c3;
  printf("%d",min);
}
