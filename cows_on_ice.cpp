#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define pp pair<long long,long long>
#define f first
#define s second
long long n,sx,sy,ex,ey;
vector<int> vec_x,vec_y,st_x,st_y;
unordered_map<string, bool> sorted_x,sorted_y,sorted_hori,sorted_vert;
unordered_map<string,vector<long long> > mp_vertical,mp_horizontal,stone_x,stone_y;
unordered_map<string,long long> vis;
bool between(long long x, long long y, long long ptr){
  return x<=ptr && y>=ptr;
}
bool between_x(long long l, long long r, string ptr){
  string going = ptr;
  if (!stone_y[going].size()) return false;
  if (l>r) swap(l,r);
  if (!sorted_y[going]) {sort(stone_y[going].begin(),stone_y[going].end());sorted_y[going] = true;}
  long long le = 0, ri = stone_y[going].size()-1;
  while(le<ri-1){
    long long mid = (le+ri)/2;
    if (between(l,r,stone_y[going][mid])) return true;
    if (r<stone_y[going][mid]) ri = mid;
    else le = mid;
  }
  return between(l,r,stone_y[going][le])||between(l,r,stone_y[going][ri]);
}
bool between_y(long long l, long long r, string ptr){
  string going = ptr;
  if (!stone_x[going].size()) return false;
  if (l>r) swap(l,r);
  if (!sorted_x[going]) {sort(stone_x[going].begin(),stone_x[going].end());sorted_x[going] = true;}
  long long le = 0, ri = stone_x[going].size()-1;

  while(le<ri-1){
    long long mid = (le+ri)/2;

    if (between(l,r,stone_x[going][mid])) return true;
    if (r>stone_x[going][mid]) le = mid;
    else ri = mid;
  }
  return between(l,r,stone_x[going][le])||between(l,r,stone_x[going][ri]);
}
long long find_up(long long x, long long y){
  string going = to_string(x);
  if (!mp_horizontal[going].size()) return -1;
  if (!sorted_hori[going]) {sort(mp_horizontal[going].begin(),mp_horizontal[going].end());sorted_hori[going] = true;}
  long long le = 0, ri = mp_horizontal[going].size()-1;
  while(le<ri-1){
    long long mid = (le+ri)/2;
    if (mp_horizontal[going][mid]<=y) le = mid;
    else ri = mid;
  }
  if (mp_horizontal[going][le]>y && !between_y(mp_horizontal[going][le],y,going)) return mp_horizontal[going][le];
  if (mp_horizontal[going][ri]>y && !between_y(mp_horizontal[going][ri],y,going)) return mp_horizontal[going][ri];
  return -1;
}
long long find_down(long long x, long long y){
  string going = to_string(x);
  if (!mp_horizontal[going].size()) return -1;
  if (!sorted_hori[going]) {sort(mp_horizontal[going].begin(),mp_horizontal[going].end());sorted_hori[going] = true;}
  long long le = 0, ri = mp_horizontal[going].size()-1;
  while(le<ri-1){
    long long mid = (le+ri)/2;
    if (mp_horizontal[going][mid]>=y) ri = mid;
    else le = mid;
  }
  if (mp_horizontal[going][ri]< y && !between_y(mp_horizontal[going][ri],y,going)) return mp_horizontal[going][ri];
  if (mp_horizontal[going][le]<y  && !between_y(mp_horizontal[going][le],y,going)) return mp_horizontal[going][le];
  return -1;
}
long long find_left(long long x, long long y){
  string going = to_string(y);
  if (!mp_vertical[going].size()) return -1;
  if (!sorted_vert[going]) {sort(mp_vertical[going].begin(),mp_vertical[going].end());sorted_vert[going] = true;}
  long long le = 0, ri = mp_vertical[going].size()-1;
  while(le<ri-1){
    long long mid = (le+ri)/2;
    if (mp_vertical[going][mid]>=x) ri = mid;
    else le = mid;
  }
  if (mp_vertical[going][ri]<x && !between_x(x,mp_vertical[going][ri],going)) return mp_vertical[going][ri];
  if (mp_vertical[going][le]<x && !between_x(x,mp_vertical[going][le],going)) return mp_vertical[going][le];
  return -1;
}
long long find_right(long long x, long long y){
  string going = to_string(y);
  if (!mp_vertical[going].size()) return -1;
  if (!sorted_vert[going]) {sort(mp_vertical[going].begin(),mp_vertical[going].end());sorted_vert[going] = true;}
  long long le = 0, ri = mp_vertical[going].size()-1;
  while(le<ri-1){
    long long mid = (le+ri)/2;
    if (mp_vertical[going][mid]<=x) le = mid;
    else ri = mid;
  }
  if (mp_vertical[going][le]>x && !between_x(x,mp_vertical[going][le],going)) return mp_vertical[going][le];
  if (mp_vertical[going][ri]>x && !between_x(x,mp_vertical[going][ri],going)) return mp_vertical[going][ri];
  return -1;
}
void find_all(int x ,int y){
  cout << find_up(x,y) << " " << find_down(x,y) << " " << find_left(x,y) << " " << find_right(x,y) << endl;
}
int main(){
  scanf("%lld%lld%lld%lld%lld",&n,&sx,&sy,&ex,&ey);
  sx+=1e9;sy+=1e9;ex+=1e9;ey+=1e9;
  for (long long i=0;i<n;i++){
    long long a,b;scanf("%lld%lld",&a,&b);
    a+=1e9;b+=1e9;
    stone_x[to_string(a)].push_back(b);
    stone_y[to_string(b)].push_back(a);
    if (a-1>=0) mp_vertical[to_string(b)].push_back(a-1);
    mp_vertical[to_string(b)].push_back(a+1);vec_x.push_back(a+1);
    if (b-1>=0) mp_horizontal[to_string(a)].push_back(b-1);
    mp_horizontal[to_string(a)].push_back(b+1);
  }
  queue<pp> q;
  q.push(make_pair(sx,sy));
  vis[to_string(sx)+"?"+to_string(sy)] = 0;
  while(!q.empty()){
    long long qf = q.front().f, qs = q.front().s; q.pop();
    long long prev = vis[to_string(qf)+"?"+to_string(qs)];
    if (qf==ex && qs==ey) {cout << prev;return 0;}
    long long le = find_left(qf,qs), ri = find_right(qf,qs), up = find_up(qf,qs), down = find_down(qf,qs);
    if (le!=-1){
      if (!vis[to_string(le)+"?"+to_string(qs)] && (le!=sx || qs!=sy)){
        vis[to_string(le)+"?"+to_string(qs)] = prev+1;
        q.push(make_pair(le,qs));
      }
    }
    if (ri!=-1){
      if (!vis[to_string(ri)+"?"+to_string(qs)] && (ri!=sx || qs!=sy)){
        vis[to_string(ri)+"?"+to_string(qs)] = prev+1;
        q.push(make_pair(ri,qs));
      }
    }
    if (up!=-1){
      if (!vis[to_string(qf)+"?"+to_string(up)] && (qf!=sx || up!=sy)){
        vis[to_string(qf)+"?"+to_string(up)] = prev+1;
        q.push(make_pair(qf,up));
      }
    }
    if (down!=-1){
      if (!vis[to_string(qf)+"?"+to_string(down)] && (qf!=sx || down!=sy)){
        vis[to_string(qf)+"?"+to_string(down)] = prev+1;
        q.push(make_pair(qf,down));
      }
    }
  }
}
/*
9
0 0 -2 -3
-3 0
-2 -2
-3 -3
-1 -3
-1 -4
-2 -4
-3 -4
-2 -5
0 -3*/
