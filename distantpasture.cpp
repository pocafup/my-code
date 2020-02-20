#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 200000000;
int pos[31][31];
int dist[31][31];
int main(){
  int a,b,c; cin >> a >> b>> c;
  int ans = 0;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      char d; cin >> d;
      if (d=='(')pos[i][j] = 1;
      else pos[i][j] = 0;
    }
  }
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      for (int k=0;k<a;k++){
        for (int l=0;l<a;l++){
          dist[k][l] = INF;
        }
      }
      dist[i][j] = 0;
      priority_queue<pair<int,int> > q;
      q.push(make_pair(i,j));
      while(!q.empty()){
        int qt = q.top().first;
        int qs = q.top().second;
        q.pop();
        for (int k=0;k<4;k++){
          if (qt+x[k]>=0 && qs+y[k]>=0 && qt+x[k]<a&&qs+y[k]<a){
            //cout << " aa" << endl;
            int go = pos[qt][qs]==pos[qt+x[k]][qs+y[k]] ? b : c;
            if (dist[qt+x[k]][qs+y[k]]>dist[qt][qs]+go){
              q.push(make_pair(qt+x[k],qs+y[k]));

              dist[qt+x[k]][qs+y[k]] = dist[qt][qs]+go;
            }
          }
        }
      }
      for (int k=0;k<a;k++){
        for (int l=0;l<a;l++){
          //cout << dist[k][l] << " ";
          if (dist[k][l]>ans) ans = dist[k][l];
        }
        //cout << endl;
      }
    }
  }
  cout << ans;
}
