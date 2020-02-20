#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cstring>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
unordered_map<int,pair<int,vector<int> > > mp1,mp2;
int n,m,tot=0,head[10005];
int dist[100005];
struct Road{
  int from,to,dis1,dis2,nxt;
}edge[50005];
void add(int f, int t, int d1, int d2){
  edge[++tot].from = f;
  edge[tot].to = t;
  edge[tot].dis1 = d1;
  edge[tot].dis2 = d2;
  edge[tot].nxt = head[f];
  head[f] = tot;
}
bool vis[10005];
void spfa(int pos){
  mp1[pos].f = 0;
  mp1[pos].s.push_back(1);
  mp2[pos].f = 0;
  mp2[pos].s.push_back(1);
  queue<int> q;
  q.push(1);
  while(!q.empty()){
    int qf = q.front();q.pop();
    vis[qf] = false;
    for (int i=head[qf];i;i=edge[i].nxt){
      int t = edge[i].to, d1 = edge[i].dis1 ,d2 = edge[i].dis2;
      if (mp1[t].f == 0 || mp2[t].f == 0 || mp1[t].f> mp1[qf].f+d1 || mp2[t].f>mp2[qf].f+d2 && !vis[t]) {q.push(t);vis[t]=true;}
      if (mp1[t].f==0 || mp1[t].f>mp1[qf].f+d1){
        mp1[t].f=mp1[qf].f+d1;
        mp1[t].s=mp1[qf].s;
        mp1[t].s.push_back(t);

      }
      if (mp2[t].f==0 || mp2[t].f>mp2[qf].f+d2){
        mp2[t].f=mp2[qf].f+d2;
        mp2[t].s=mp2[qf].s;
        mp2[t].s.push_back(t);
      }
    }
  }
}
int found(vector<int> vec, int pos){
  int l = 0, r = vec.size()-1;
  // cout << l << " " << r << endl;
  while(l!=r-1){
    int mid = (l+r)/2;
    if (vec[mid]==pos) return false;
    if (vec[mid]>pos) r = mid;
    else l = mid;
    // cout << l << " " << r << endl;
  }
  return vec[l]!=pos && vec[r]!=pos;
}
vector<int> e_vec_1,e_vec_2;
void spfa2(int pos){
  memset(dist,0x3f3f,sizeof(dist));
  dist[pos] = 0;
  queue<int> q;
  q.push(pos);
  while(!q.empty()){
    int qf = q.front();q.pop();
    // cout << qf << endl;
    vis[qf] = false;
    for (int i = head[qf];i;i=edge[i].nxt){
      int t = edge[i].to;
      int d1 = found(e_vec_1,t),d2 = found(e_vec_2,t);
      cout << "t : " << t << " qf " <<qf << " " << dist[qf] << " " << d1 << " " << d2 << endl;
      if (dist[t]>dist[qf]+d1+d2){
        dist[t] = dist[qf]+d1+d2;
        if (!vis[t]) {vis[t] = true;q.push(t);}
      }
    }
  }
}
int main(){
  cin >> n >> m;
  for (int i=0;i<m;i++){
    int a,b,c,d; cin >> a >> b >> c >> d;
    add(a,b,c,d);
  }
  spfa(1);

  for (int i : mp1[n].s) {cout << i << " " ;e_vec_1.push_back(i);}
  cout << endl;
  for (int i : mp2[n].s) {cout << i << " " ;e_vec_2.push_back(i);}
  cout << endl;
  sort(e_vec_1.begin(),e_vec_1.end());
  sort(e_vec_2.begin(),e_vec_2.end());
  spfa2(1);
  cout << dist[n];
  // cout << endl;
}
/*
5 7
3 4 7 1
1 3 2 20
1 4 17 18
4 5 25 3
1 2 10 1
3 5 4 14
2 4 6 5
*/
