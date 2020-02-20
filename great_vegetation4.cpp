#include <iostream>
#include <algorithm>

using namespace std;
int n,k,fat[100005];
bool vis[100005];
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
  for (register int i=1;i<=n;i++)fat[i] = i;
  for (register int i=0;i<k;i++){
    char a; int b,c; cin >> a >> b >> c;
    if (a=='S') Union(b,c);
    else if (father(b)==father(c)) {cout<<0; return 0;}
  }
  cout << 1;
  for (int i=1;i<=n;i++) if (father(i)!=i && !vis[father(i)]) {vis[father(i)] = true;cout << 0;}
}
