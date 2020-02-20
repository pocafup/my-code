#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
#define ri register int

template <typename T>inline void redi(T& t)
{
    ri c=getchar();t=0;
    while(!isdigit(c))c=getchar();
    while(isdigit(c))t=t*10+c-48,c=getchar();
}
template <typename T,typename... Args> inline void redi(T& t, Args&... args)
{
    redi(t);redi(args...);
}
int main(){
  long long a,b; redi(a,b);
  b--;
  for (int i=a-1;i>=0;i--){
    int re = pow(2,i);
    if (a>re){
      cout << 1;
      a-=re;
    }else cout << 0;
  }
}
