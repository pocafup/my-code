 #include <iostream>
#include <algorithm>
#include<fstream>


using namespace std;
int n,m,tot=0,head[100005];
string s;
struct Edge{
  int from,to,next;
}edge[200005];
void add(int f, int t){
  edge[++tot].to = t;
  edge[tot].from = f;
  edge[tot].next = head[f];
  head[f] = tot;
}

void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}
int vis[100005];
void dfs(int pos, int put){
  // cout << pos << "     " << put << endl;
  vis[pos] = put;
  for (int i=head[pos];i;i=edge[i].next){
    if (!vis[edge[i].to] && s[pos]==s[edge[i].to]) dfs(edge[i].to,put);
  }
}
int main(){
  setIO("milkvisits");
  cin >> n >> m >> s;
  for (int i=0;i<n-1;i++){
    int a,b; cin >> a >> b;
    add(a,b); add(b,a);
  }
  for (int i=s.length()-1;i>=0;i--) s[i+1] = s[i];
  s[0] = 0;
  for (int i=1;i<=n;i++) if (!vis[i]) dfs(i,i);
  // for (int i=1;i<=n;i++) cout << vis[i] << endl;
  for (int i=0;i<m;i++){
    int a,b; char c; cin >> a >> b >> c;
    cout << (s[a]==c || s[b] == c || vis[a]!=vis[b]);
  }
}
