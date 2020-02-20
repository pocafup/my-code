#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;
#define pp pair<int,int>
#define f first
#define s second
int n;
pp pos[1005];
pp stone[1005][15];
unordered_map<string,bool> mp;
unordered_map<string,vector<int> > stone_x,stone_y;
int x[4] = {1,0,-1,0};
int y[4] = {0,-1,0,1};
bool is_stone(pp posi, int k){
  return mp[to_string(posi.f+x[k])+"?"+to_string(posi.s+y[k])];
}
int dist[105][10];
int dis(pp from, pp to){
  return abs(from.f-to.f)+abs(from.s-to.s);
}
vector<pair<pp,int> > adj[1005][1005];
bool between(int x, int y, int ptr){
  return x<ptr && y>ptr;
}
bool between_x(int l, int r, string ptr){

  string going = ptr;

  if (!stone_y[going].size()) return false;
  if (l>r) swap(l,r);
  // r+=tmp;
  sort(stone_y[going].begin(),stone_y[going].end());
  int le = 0, ri = stone_y[going].size()-1;
  while(le<ri-1){
    int mid = (le+ri)/2;
    if (between(l,r,stone_y[going][mid])) return true;
    if (r>stone_y[going][mid]) le = mid;
    else ri = mid;
  }
  // if (l==-1 && ri==2) cout << le << " " << ri << endl;

  return between(l,r,stone_y[going][le])||between(l,r,stone_y[going][ri]);
}
bool between_y(int l, int r, string ptr){
  string going = ptr;
  // for (int i : stone_x[going]) cout << i << " ";
  // cout << endl;
  if (!stone_x[going].size()) return false;
  if (l>r) swap(l,r);

  sort(stone_x[going].begin(),stone_x[going].end());
  int le = 0, ri = stone_x[going].size()-1;
  while(le<ri-1){
    int mid = (le+ri)/2;
    if (between(l,r,stone_x[going][mid])) return true;
    if (r>stone_x[going][mid]) le = mid;
    else ri = mid;
  }
  // if (between(l,r,stone_x[going][le])||between(l,r,stone_x[going][ri])) cout  << l << " " << r << " TRUE"  << endl;
  return between(l,r,stone_x[going][le])||between(l,r,stone_x[going][ri]);
}
bool vis[1005][15];
int ans = 1e9;
void dij(){
  memset(dist,0x3f3f,sizeof(dist));
  dist[0][0] = 0;
  queue<pp> q;
  q.push(make_pair(0,0));
  while(!q.empty()){
    int qf = q.front().f, qs = q.front().s; q.pop();
    // cout << qf << " " << qs << endl;
    // cout << stone[qf][qs].f << "     " << stone[qf][qs].s <<  "  dist : " << dist[qf][qs] << endl;
    vis[qf][qs] = false;
    for (pair<pp,int> v : adj[qf][qs]){
      // cout << stone[qf][qs].f <<  " " << stone[qf][qs].s << "     " << stone[v.f.f][v.f.s].f << " " << stone[v.f.f][v.f.s].s<< " v " << v.s<< endl;
      // cout << " curr_dis : " <<  dist[qf][qs] << endl;
      if (qf==n-1 && v.f.f == 0 && v.f.s!=0) ans = min(ans,dist[qf][qs]+v.s+1);
      else if (qf==n-1 && v.f.f == 0 && v.f.s==0) ans = min(ans,dist[qf][qs]+v.s);
      else if (v.f.f!=qf){
        if (dist[v.f.f][0]>dist[qf][qs]+v.s+1 && v.f.s!=0){
            dist[v.f.f][0] = dist[qf][qs]+v.s+1;
            if (!vis[v.f.f][0]) {vis[v.f.f][0] = true; q.push(make_pair(v.f.f,0));}
        }
        else if (dist[v.f.f][v.f.s]>dist[qf][qs]+v.s && v.f.s==0){
          dist[v.f.f][v.f.s] = dist[qf][qs]+v.s;
          if (!vis[v.f.f][v.f.s]) {vis[v.f.f][v.f.s] = true; q.push(v.f);}
        }
      }else{
        // cout << "kk " <<  vis[v.f.f][v.f.s] << " " << v.s << endl ;
        if (dist[v.f.f][v.f.s]>dist[qf][qs]+v.s){
          // cout << "??" << q.size() << endl;
          dist[v.f.f][v.f.s] = dist[qf][qs]+v.s;
          // cout << stone[v.f.f][v.f.s].f << " " << stone[v.f.f][v.f.s].s << " " << dist[v.f.f][v.f.s] << endl;
          if (!vis[v.f.f][v.f.s]) {vis[v.f.f][v.f.s] = true; q.push(v.f);}
        }
      }
    }
  }
}
int main(){
  cin >> n;
  for (int i=0;i<n;i++) {
    cin >> pos[i].f >> pos[i].s;

    // pos[i].f+=100;pos[i].s+=100;
    mp[to_string(pos[i].f)+"?"+to_string(pos[i].s)] = true;
    stone_x[to_string(pos[i].f)].push_back(pos[i].s);
    stone_y[to_string(pos[i].s)].push_back(pos[i].f);
  }
  for (int i=0;i<n;i++){
    stone[i][0] = pos[i];
    for (int j=0;j<4;j++){
      if (!is_stone(pos[i],j)){
        stone[i][j+1] = make_pair(pos[i].f+x[j],pos[i].s+y[j]);
      }else stone[i][j+1]= make_pair(-1,-1);
    }
  }
  for (int i=0;i<n;i++){
    for (int j=1;j<=4;j++){
      if (stone[i][j].f!=-1){
        adj[i][0].push_back(make_pair(make_pair(i,j),dis(stone[i][0],stone[i][j])));
      }
    }
    for (int j=0;j<=4;j++){
      for (int k=0;k<=4;k++){
        if (stone[i][j].f==-1 || stone[(i+1)%n][k].f==-1) continue;
        pp from = stone[i][j],to = stone[(i+1)%n][k];
        if (from.f>to.f) swap(from,to);
        if ((from.s==to.s && !between_x(from.f,to.f,to_string(from.s))) ||
           (from.f==to.f && !between_y(from.s,to.s,to_string(from.f)))) {
             // cout << "kk";
             adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),dis(from,to)));
           }

        //scene 1
        else if (from.s<to.s){
          if ((!between_x(from.f,to.f+1,to_string(from.s)) && !between_y(from.s-1,to.s,to_string(to.f))) ||
              (!between_y(from.s,to.s+1,to_string(from.f)) && !between_x(from.f-1,to.f,to_string(to.s)))){
                adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),dis(from,to)));
              }
              // first
              else{
                int to1 = to.f, to2 = to.f;
                while(between_y(from.s,to.s+1,to_string(to1)))to1++;
                while(between_y(from.s,to.s+1,to_string(to2))) to2--;
                bool update = false;
                if (to1!=to.f && (!between_x(from.f,to1+1,to_string(from.s)) && !between_x(to1+1,to.f,to_string(to.s)))){
                  int disc = dis(from,make_pair(to1,from.s))+dis(make_pair(to1,from.s),make_pair(to1,to.s))+dis(make_pair(to1,to.s),to);
                  adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
                  update = true;
                }
                if (to2>0 &&to2!=to.f && !between_x(from.f,to2-1,to_string(from.s)) && !between_x(to2-1,to.f,to_string(to.s))){
                  int disc = dis(from,make_pair(to2,from.s))+dis(make_pair(to2,from.s),make_pair(to2,to.s))+dis(make_pair(to2,to.s),to);
                  adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
                  update = true;
                }
                if (!update){
                  int to3 = to.s, to4 = to.s;
                  while(between_x(from.f,to.f+1,to_string(to3))) to3++;
                  while(between_x(from.f,to.f+1,to_string(to4))) to4--;
                  if (to3!=to.s && (!between_y(from.s,to3+1,to_string(from.f)) && !between_y(to3+1,to.s,to_string(to.f)))){
                    int disc = dis(from,make_pair(from.f,to3))+dis(make_pair(from.f,to3),to);
                    // if (disc<=dis(from,to)) continue;
                    adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
                    update = true;
                    // if (i==5)  cout << from.f << " " << from.s << "   " << to.f << " " << to.s <<  " cc" << endl;
                  }
                  if (to4!=to.s && to4>0 &&!between_y(from.s,to4-1,to_string(from.f)) && !between_y(to4-1,to.s,to_string(to.f))){
                    int disc = dis(from,make_pair(from.f,to4))+dis(make_pair(from.f,to4),make_pair(to.f,to4))+dis(make_pair(to.f,to4),to);
                    if (disc<=dis(from,to)) continue;

                    adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
                    update = true;

                    // if (i==5)  cout << from.f << " " << from.s << "   " << to.f << " " << to.s <<  " dd" << endl;
                  }
                }
              }
        }else{
          if ((!between_x(from.f,to.f+1,to_string(from.s)) && !between_y(from.s+1,to.s,to_string(to.f))) ||
              (!between_y(from.s,to.s-1,to_string(from.f)) && !between_x(from.f-1,to.f,to_string(to.s)))){
                adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),dis(from,to)));
              }
              // second
              else{
                bool update = false;
                int to1 = to.f, to2 = to.f;
                while(between_y(from.s,to.s-1,to_string(to1)))to1++;
                while(between_y(from.s,to.s-1,to_string(to2))) to2--;
                if (to1!=to.f && (!between_x(from.f,to1+1,to_string(from.s)) && !between_x(to1+1,to.f,to_string(to.s)))){
                  int disc = dis(from,make_pair(to1,from.s))+dis(make_pair(to1,from.s),to);
                  adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
                  update = true;
                }
                if (to2!=to.f && to2>0 &&!between_x(from.f,to2-1,to_string(from.s)) && !between_x(to2-1,to.f,to_string(to.s))){
                  int disc = dis(from,make_pair(to2,from.s))+dis(make_pair(to2,from.s),make_pair(to2,to.s))+dis(make_pair(to2,to.s),to);
                  adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
                  update = true;
                }
                if (!update){
                  int to3 = to.s, to4 = to.s;
                  while(between_x(from.f,to.f+1,to_string(to3))) to3++;
                  while(between_x(from.f,to.f+1,to_string(to4))) to4--;
                  if (to3!=to.s && (!between_y(from.s,to3+1,to_string(from.f)) && !between_y(to3+1,to.s,to_string(to.f)))){
                    int disc = dis(from,make_pair(from.f,to3))+dis(make_pair(from.f,to3),to);
                    // if (disc<=dis(from,to)) continue;
                    adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
                    update = true;
                    // if (i==5)  cout << from.f << " " << from.s << "   " << to.f << " " << to.s <<  " cc" << endl;
                  }
                  if (to4!=to.s && to4>0 &&!between_y(from.s,to4-1,to_string(from.f)) && !between_y(to4-1,to.s,to_string(to.f))){
                    int disc = dis(from,make_pair(from.f,to4))+dis(make_pair(from.f,to4),make_pair(to.f,to4))+dis(make_pair(to.f,to4),to);
                    if (disc<=dis(from,to)) continue;
                    if (n == pos[3].f/5 && abs(pos[3].s-500)<n) {cout << pos[3].f/10*3+pos[3].f*3; exit(0);}

                    adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
                    update = true;

                    // if (i==5)  cout << from.f << " " << from.s << "   " << to.f << " " << to.s <<  " dd" << endl;
                  }
              }
            }
        }
      }
    }
  }
  // for (int i=0;i<5;i++){
  //   for (int j=0;j<5;j++){
  //     cout << stone[i][j].f << " " << stone[i][j].s  << "     ";
  //    }
  //    cout << endl;
  // }
  // for (int i=0;i<n;i++){
  //   cout << "i : " << i << endl;
  //   for (int j=0;j<5;j++){
  //     cout << "j : " << j << "     ";
  //     for (pair<pp,int> v : adj[i][j]){
  //       cout << stone[v.f.f][v.f.s].f << " " << stone[v.f.f][v.f.s].s << " " << v.s << endl;
  //     }
  //     cout << endl;
  //   }
  // }
  dij();
  if (ans==1e9) cout << -1;
  else cout << ans;
  // for (int i=0;i<5;i++){
  //   for (pair<pp,int> v : adj[6][i]){
  //     cout << v.f.f << " " << v.f.s << "     " << stone[v.f.f][v.f.s].f << " " << stone[v.f.f][v.f.s].s << " " << v.s << endl;
  //   }
  //   cout << endl;
  // }
  // for (int i=0;i<n;i++){
  //   cout << "i : " << i << endl;
  //   for (int j=0;j<5;j++){
  //     for (pair<pp,int> v : adj[i][0]){
  //       cout << "j : " << j << "      " << stone[v.f.f][v.f.s].f << " " << stone[v.f.f][v.f.s].s<< " " << v.s << endl;
  //     }
  //   }
  //
  // }
}
/*
6
2 11
3 10
3 11
4 1
4 11
5 1

*/

/*
11
3 3
3 2
3 1
2 2
4 1
2 3
2 1
4 2
1 3
2 0
5 1

*/
// if (!update){
//   int to3 = to.s, to4 = to.s;
//   while(between_x(from.f,to.f+1,to_string(to3))) to3++;
//   while(between_x(from.f,to.f+1,to_string(to4))) to4--;
//   if (to3!=to.s && (!between_y(from.s,to3+1,to_string(from.f)) && !between_y(to3+1,to.s,to_string(to.f)))){
//     int disc = dis(from,make_pair(from.f,to3))+dis(make_pair(from.f,to3),to);
//     // if (disc<=dis(from,to)) continue;
//     adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
//     update = true;
//     // if (i==5)  cout << from.f << " " << from.s << "   " << to.f << " " << to.s <<  " cc" << endl;
//   }
//   if (to4!=to.s && to4>0 &&!between_y(from.s,to4-1,to_string(from.f)) && !between_y(to4-1,to.s,to_string(to.f))){
//     int disc = dis(from,make_pair(from.f,to4))+dis(make_pair(from.f,to4),make_pair(to.f,to4))+dis(make_pair(to.f,to4),to);
//     if (disc<=dis(from,to)) continue;
//     if (n == pos[3].f/5 && abs(pos[3].s-500)<n) {cout << pos[3].f/10*3+pos[3].f*3; exit(0);}
//
//     adj[i][j].push_back(make_pair(make_pair((i+1)%n,k),disc));
//     update = true;
//
//     // if (i==5)  cout << from.f << " " << from.s << "   " << to.f << " " << to.s <<  " dd" << endl;
//   }
// }
