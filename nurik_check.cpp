#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int x[3] = {1,0,1};
int y[3] = {0,1,1};
int xpos[4] = {1,0,-1,0};
int ypos[4] = {0,-1,0,1};
bool check(pair<int,int> aa, int b,int cc, int dd){
  return aa.first+xpos[b]<cc && aa.second+ypos[b]<dd && aa.first+xpos[b]>=0 && aa.second+ypos[b]>=0;
}
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++){
    int b,c,d; cin >> b >> c >>d;
    bool correct = true;
    char grid[b][c];
    int num[b][c];
    bool vis[b][c];
    memset(num,0,sizeof(num));
    memset(vis,0,sizeof(vis));
    pair<int,int> st = make_pair(-1,-1);
    int count_st = 0;
    for (int j=0;j<b;j++){
      for (int k=0;k<c;k++){
        cin >> grid[j][k];
        if (grid[j][k] == '#'){st = make_pair(j,k);count_st++;}
      }
    }
    //check 2*2
    for (int j=0;j<b-1;j++){
      for (int k=0;k<c-1;k++){
        bool ok = false;

        if (grid[j][k]=='#'){
          ok = true;
          for (int l=0;l<3;l++){
            if (grid[j+x[l]][k+y[l]]=='.') ok = false;
          }
        }
        if (ok) correct = false;
      }
    }
    queue<pair<int,int> > q;

    //check grid consec white cells

    for (int j=0;j<d;j++){
      int xi,yi,m; cin >> xi >> yi >> m;
      xi--;yi--;
      if (vis[xi][yi]) correct = false;
      else if (grid[xi][yi]=='.'){
        vis[xi][yi] = true;
        q.push(make_pair(xi,yi));
        int cou = 1;
        vector<pair<int,int> > re;
        while(!q.empty()){
          re.push_back(q.front());
          int qf = q.front().first;
          int qs = q.front().second;
          q.pop();
          for (int l=0;l<4;l++){
            if (check(make_pair(qf,qs),l,b,c)){
              if (!vis[qf+xpos[l]][qs+ypos[l]] && grid[qf+xpos[l]][qs+ypos[l]]=='.'){
                vis[qf+xpos[l]][qs+ypos[l]] = true;
                cou++;
                // cout << qf+xpos[l] << " " << qs+ypos[l] << endl;
                q.push(make_pair(qf+xpos[l],qs+ypos[l]));
              }
            }
          }
        }
        while(!re.empty()){
          num[re[re.size()-1].first][re[re.size()-1].second] = cou;
          re.pop_back();
        }
      }
      // cout << "m = " << num[xi][yi] << " " << m << endl;
      if (num[xi][yi]!=m) correct = false;
    }
    for (int j=0;j<b;j++){
      for (int k=0;k<c;k++){
        if (grid[j][k]=='.' && num[j][k]==0) correct = false;
      }
    }
    //check blackstream

    if (st.first!=-1){
      q.push(st);
      vis[st.first][st.second] = true;
      int curr = 1;
      while(!q.empty()){
        int qf = q.front().first;
        int qs = q.front().second;
        q.pop();
        for (int l=0;l<4;l++){
          if (check(make_pair(qf,qs),l,b,c)){
            if (!vis[qf+xpos[l]][qs+ypos[l]] && grid[qf+xpos[l]][qs+ypos[l]]=='#'){
              vis[qf+xpos[l]][qs+ypos[l]] = true;
              curr++;
              q.push(make_pair(qf+xpos[l],qs+ypos[l]));
            }
          }
        }
      }
      if (curr!=count_st) {correct = false;}

    }

    // cout << "curr and count_st = " << curr << " " << count_st << endl;
    if (correct) cout << "Puzzle #" << i+1 << ":" <<  " Correct" << endl;
    else cout << "Puzzle #" << i+1 << ":" <<  " Incorrect" << endl;
  }
}
