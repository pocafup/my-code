#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
// #define pp pair<int,int>;
int a,b;

char grid[1001][1001];
bool vis[1001][1001];
bool in_list[1001][1001];
bool check(int fir, int sec){
  return (fir>=0 && fir<a && sec>=0 && sec<b);
}

bool check_knight(int fir,int sec){
  int x3[8] = {1,1,1,0,-1,-1,-1,0};
  int y3[8] = {1,0,-1,-1,-1,0,1,1};
  for (int i=1;i<8;i+=2){
    if (check(fir+x3[i],sec+y3[i]) &&
        check(fir+x3[i-1],sec+x3[i-1]) &&
        check(fir+x3[(i+5)%8],sec+y3[(i+5)%8])){
          if (grid[fir+x3[i]][sec+y3[i]] == 'A' &&
              grid[fir+x3[i-1]][sec+y3[i]] == '.' &&
              grid[fir+x3[(i+5)%8]][sec+y3[(i+5)%8]]=='A'){
                return true;
              }
        }

    if (check(fir+x3[i],sec+y3[i]) &&
        check(fir+x3[(i+1)%8],sec+x3[(i+1)%8]) &&
        check(fir+x3[(i+3)%8],sec+y3[(i+3)%8])){
          if (grid[fir+x3[i]][sec+y3[i]] == 'A' &&
              grid[fir+x3[(i+1)%8]][sec+y3[(i+1)%8]] == '.' &&
              grid[fir+x3[(i+3)%8]][sec+y3[(i+3)%8]]=='A'){
                return true;
              }
        }
    }
    return false;
}
bool check_opp(int fir, int sec){
  if (grid[fir][sec]=='A') return false;
  int test_x[4] = {1,0,-1,0};
  int test_y[4] = {0,-1,0,1};
  for (int i=0;i<2;i++){
    if (check(fir+test_x[i],sec+test_y[i]) &&
        check(fir+test_x[i+2],sec+test_y[i+2])){
          if (grid[fir+test_x[i]][sec+test_y[i]] == 'A' &&
              grid[fir+test_x[i+2]][sec+test_y[i+2]] == 'A'){
                return true;
              }
        }
  }
  return false;
}
bool check_three(int fir,int sec){
  int test_x[4] = {1,0,-1,0};
  int test_y[4] = {0,-1,0,1};
  for (int i=0;i<4;i++){
    if (check(fir+test_x[i],sec+test_y[i]) &&
        check(fir+test_x[(i+1)%4],sec+test_y[(i+1)%4]) &&
        check(fir+test_x[(i+2)%4],sec+test_y[(i+2)%4])){
          if (grid[fir+test_x[i]][sec+test_y[i]] == 'A' &&
              grid[fir+test_x[(i+1)%4]][sec+test_y[(i+1)%4]] == 'A' &&
              grid[fir+test_x[(i+2)%4]][sec+test_y[(i+2)%4]] == 'A'){
                return true;
              }
        }
  }
  return false;
}
bool check_two(int fir,int sec){
  int test_x[4] = {1,0,-1,0};
  int test_y[4] = {0,-1,0,1};
  int d_x[8] = {1,1,0,-1,-1,-1,0,1};
  int d_y[8] = {0,-1,-1,-1,0,1,1,1};
  for (int i=0;i<4;i++){
    if (check(fir+test_x[i],sec+test_y[i]) &&
        check(fir+test_x[(i+1)%4],sec+test_y[(i+1)%4])){
          if (grid[fir+test_x[i]][sec+test_y[i]] == 'A' &&
              grid[fir+test_x[(i+1)%4]][sec+test_y[(i+1)%4]] == 'A'){
                bool check = true;
                for (int j=i*2+4;j<i*2+7;j++){
                  if (grid[fir+d_x[j%8]][sec+d_y[j%8]]=='A'|| grid[fir+d_x[j%8]][sec+d_y[j%8]]=='x') check = false;

                }
                if (check) return true;
              }
        }
  }
  return false;
}
int main(){
  cin >> a >> b;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> grid[i][j];
    }
  }

  int x[8] = {1,1,1,0,-1,-1,-1,0};
  int y[8] = {1,0,-1,-1,-1,0,1,1};
  queue<pair<int,int> > q;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      for (int k=0;k<8;k++){
        if (grid[i][j] == 'A'){
          if (check(i+x[k],j+y[k])){
            if (grid[i+x[k]][j+y[k]]=='.' && !vis[i+x[k]][j+y[k]]){
              if (!in_list[i+x[k]][j+y[k]]) {
                q.push(make_pair(i+x[k],j+y[k]));
                in_list[i+x[k]][j+y[k]] = true;
                vis[i+x[k]][j+y[k]] = true;
              }

            }
          }
        }
      }
    }
  }
  int detect_consec_x[4] = {-1,0,1,0};
  int detect_consec_y[4] = {0,-1,0,1};
  while(!q.empty()){
    int qf = q.front().first;
    int qs = q.front().second;
    q.pop();
    in_list[qf][qs] = false;
    if (check_three(qf,qs) || check_two(qf,qs)){
      grid[qf][qs] = 'A';
      for (int k=0;k<8;k++){
        if (check(qf+x[k],qs+y[k])){
          if (grid[qf+x[k]][qs+y[k]]=='.' && in_list[qf+x[k]][qs+y[k]] == false) {
            q.push(make_pair(qf+x[k],qs+y[k]));
            in_list[qf+x[k]][qs+y[k]] = true;
          }
        }
      }
    }
  }
  int x2[4] = {1,0,-1,0};
  int y2[4] = {0,-1,0,1};
  pair<int,int> start;
  queue<pair<int,int> > q2;
  int fu = false;
  memset(vis,0,sizeof(vis));
  for(int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (grid[i][j] == 'A'){
        q2.push(make_pair(i,j-1));
        fu = true;
        vis[i][j-1] = true;
        break;
      }
    }
    if (fu) break;
  }
  int ans = 0;
  while(!q2.empty()){
    int qf = q2.front().first;
    int qs = q2.front().second;
    q2.pop();
    bool plus = false;
    for (int k=0;k<8;k++){
      if (check(qf+x[k],qs+y[k])){
        if (grid[qf+x[k]][qs+y[k]]=='A'){
          plus = true;
          break;
        }
      }
    }
    if (plus) {
      ans++;
      int cur = 0;
      if (check_knight(qf,qs)) ans ++;
      else if (check_opp(qf,qs)) ans++;
      else{
        for (int i=0;i<4;i++){
          if (check(qf+x2[i],qs+y2[i])){
            if (check_opp(qf+x2[i],qs+y2[i]))cur++;
          }
        }
        if (cur>=1){
          ans += max(1,cur-1);
        }
      }
    }
    for (int i=0;i<4;i++){
      if (check(qf+x2[i],qs+y2[i])){
        if (!vis[qf+x2[i]][qs+y2[i]] && grid[qf+x2[i]][qs+y2[i]]=='.'){
          vis[qf+x2[i]][qs+y2[i]] = true;
          q2.push(make_pair(qf+x2[i],qs+y2[i]));
        }
      }
    }
  }

  cout << ans;
}
