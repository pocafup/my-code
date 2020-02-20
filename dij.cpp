#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
#define INF 200000000;
int graph[30][30];

priority_queue<pair<pair<int,int>, int> > q;
int dist[30][30];
int main(){
  int maxi = 0;
  int a,b,c; cin >> a >> b >> c;
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      char d; cin >> d;
      if (d == '(') graph[i][j] = 1; else graph[i][j] = 0;
    }
  }
  for (int i=0;i<a;i++)
    for (int j=0;j<a;j++)
      dist[i][j] = INF;

  dist[0][0] = 0;
  //q.push(make_pair(make_pair(0,0),0));
  int x[4] = {0,1,0,-1};
  int y[4] = {1,0,-1,0};
  for (int i=0;i<a;i++){
    for (int j=0;j<a;j++){
      q.push(make_pair(make_pair(i,j),dist[i][j]));
      while(!q.empty()){

        int cX = q.top().first.first;
        int cY = q.top().first.second;
        //cout << cX << " " << cY << endl;
        maxi = max(maxi,dist[cX][cY]);
        for (int i=0;i<4;i++){
          int nX = cX+x[i];
          int nY = cY+y[i];
          if (nX>=0 && nY>=0 && nX<a && nY<a){
                  // cout << nX << " zz " << nY << " zz " << endl << endl;
              int zz = (graph[nX][nY] ==
                        graph[cX][cY]) ? b:c;

              if(dist[cX][cY]+zz < dist[nX][nY]){
                 dist[nX][nY] = dist[cX][cY]+zz;
                 q.push(make_pair(make_pair(nX,nY),
                         dist[nX][nY]));


            }
          }
        }

        q.pop();
      }

    }
  }

//   cout << endl;
//   for (int i=0;i<a;i++){
//     for (int j=0;j<a;j++){
//       cout << dist[i][j] << " ";
//     }
//     cout << endl;
//   }
//   cout << endl;

  cout << maxi;
}
