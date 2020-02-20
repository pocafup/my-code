#include <iostream>
#include <algorithm>

using namespace std;
long long pos[100001];
long long a,b;
long long cel;
inline long long read() {
      long long x=0,w=1;
      char ch;
      while(ch<'0'||ch>'9')
      {
          if(ch=='-')
              w=-1;
          ch=getchar();
     }
     while(ch>='0'&&ch<='9')
         x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
     return x*w;
 }
long long bs(long long le, long long ri,long long re){
  while(le!=ri-1){
    long long mid = (le+ri)/2;
    if (pos[mid]<=re) le = mid;
    else ri = mid;
  }
  if (pos[ri]<re) return ri;
  return le;
}
long long find_max(bool ti){
  long long le_end = 0,ri_end = a-1,temp = 0;
  cel = b;
  while(le_end<=ri_end){
    long long fir = ti ? le_end : ri_end;
    long long sec = ti ? ri_end : le_end;
    temp += max(abs(cel-pos[fir]),abs(b-pos[fir]));
    cel = pos[fir];
    if (ti) le_end++; else ri_end--;
    if (le_end>ri_end) break;
    temp += max(abs(pos[sec]-cel),abs(pos[sec]-b));
    cel = pos[sec];
    if (ti) ri_end--; else le_end++;
  }
  return temp;
}
int main(){
  a = read(), b= read();
  cel = b;
  for (long long i=0;i<a;i++) pos[i] = read();
  sort(pos,pos+a);
  long long mini = 0,maxi = 0;
  long long res = bs(0,a-1,b);
  mini += abs(b-pos[res])+abs(pos[res]-pos[0])+min(abs(pos[a-1]-b),abs(pos[a-1]-pos[res]));
  maxi = max(find_max(0),find_max(1));
  cout << mini << " " << maxi;
}
