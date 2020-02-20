#include <iostream>
#include <algorithm>

using namespace std;
int n,k,fat[100005],ans;
bool vis[100005];
struct Cow{
  int from,to; char state;
}cow[100005];
inline int read() {
      int x=0,w=1;
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
bool sorted(Cow a, Cow b){
  return (a.state=='S')>(b.state=='S');
}
void setIO(string name) {
 	freopen((name+".in").c_str(),"r",stdin);
 	freopen((name+".out").c_str(),"w",stdout);
 	ios_base::sync_with_stdio(0);
}

int father(int x){
	while(x!=fat[x]) x=fat[x]=fat[fat[x]];
	return x;
}
void Union(int x, int y){
  fat[father(y)] = father(x);
}
int main(){
  // setIO("revegetate");
  cin >> n >> k;
  ans = n;
  for (register int i=1;i<=n;i++)fat[i] = i;
  for (int i=0;i<k;i++) cin >> cow[i].state >> cow[i].from >> cow[i].to;
  sort(cow,cow+k,sorted);
  for (int i=0;i<k;i++){
    if (cow[i].state=='S') {if (father(cow[i].from)!=father(cow[i].to)) {Union(cow[i].from,cow[i].to); ans--;}}
    else if (father(cow[i].from)==father(cow[i].to)) {cout << 0; return 0;}
    // else ans--;
  }
  cout << 1;
  while (ans>0){
    cout << 0;
    ans--;
  }
}
