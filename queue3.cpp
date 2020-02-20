#include <iostream>
#include <queue>
#include <string>
#include <cmath>
using namespace std;

void solve(){
  int nn = 1;
  int mini = 100;
  int l,k,pos= 0;
  queue<char> q;
  string d[1000];
  queue<int> xpos;
  queue<int> ypos;



  int w,h;
  bool n = true;
  cin >> w >> h;
  int visited[w][h];
  memset(visited,0,sizeof(visited));


  for (int i=0;i<w;i++){
    cin >> d[i];
  }

  bool stop = false;
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if(d[i][j]=='X' && visited[i][j] == 0){
        xpos.push(i);
        ypos.push(j);

        while(!xpos.empty()){
          visited[i][j] = nn;
          d[i][j] = 'a';
          int re1 = xpos.front();
          int re2 = ypos.front();
          int xx[4] = {re1+1,re1-1,re1,re1};
          int yy[4] = {re2,re2,re2+1,re2-1};
          //cout << re1 << " " << re2 << endl;
          for (int i=0;i<4;i++){
            int x = xx[i];
            int y = yy[i];
            if (x >= 0 && y >= 0 && x < w && y < h){
              //cout << d[x][y] << " " << visited[x][y] << " "<< x << " " << y << endl;
              //cout << "        "<< x << " " << y << endl;
              if (d[x][y] == 'X' && visited[x][y] == 0){
                visited[x][y] = nn;

                xpos.push(x);
                ypos.push(y);
                d[x][y] = 'a';

              }

            }
          }
          xpos.pop();
          ypos.pop();
        }
        stop = true;
        break;

        }

      }
      if(stop){
        break;
      }

    }
  for(int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      //cout<<d[i][j];
    }
  //cout << endl;
  }

  for (int i=0;i<w;i++){
    for(int j=0;j<h;j++){
      if (d[i][j] == 'a'){
        for(int o=0;o<w;o++){
          for(int t=0;t<h;t++){
            if (d[o][t] == 'X'){


              if (mini>abs(i-o)+abs(j-t)-1){
                mini = abs(i-o)+abs(j-t)-1;
                //cout << i << " " << j << " " << o << " " << t << endl;
                //cout <<mini << endl;
              }
            }
          }
        }
      }

    }
  }
  cout << mini;
}

int main(){
  solve();
}
