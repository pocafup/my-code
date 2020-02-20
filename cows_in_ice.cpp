#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
int n, sx,sy,ex,ey;
map<string,vector<int> > mpx;
queue<pp> q;
map<string,int> vis;
int find_vertical(int pos, int ptr){

}
int main(){
  cin >> n >> sx >> sy >> ex >> ey;
  for (int i=0;i<n;i++){
    int a,b; cin >> a >> b;
    mpx[to_string(a)].push_back(b);
    mpy[to_string(b)].push_back(a);
  }
  vis[to_string(sx)+"?"+to_string(b)] = 0;
  q.push(make_pair(sx,sy));
  while(!q.empty()){
    int qf = q.front().f,qs = q.front().s; q.pop();
    for (int i=0;i<2;i++){
      int k = find_vertical(i,qf);
      // if (find_direction(i,qf))
    }
  }
}
