#include <iostream>
#include <queue>
#include <string>

using namespace std;

void solve(){
  int maxi = 0;
  int l,k= 0;
  queue<char> q;
  string d[1000];
  queue<int> xpos;
  queue<int> ypos;


  int w,h;
  bool n = true;
  cin >> w >> h;
  bool visited[h][w];
  memset(visited,0,sizeof(visited));
  for (int i=0;i<h;i++){
    cin >> d[i];
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){

      if(d[i][j]=='*' && !visited[i][j]){
        xpos.push(i);
        ypos.push(j);
        cout << "aa" << endl;
        int counter = 0;
        while(!xpos.empty()){
          counter++;
          int re1 = xpos.front();
          int re2 = ypos.front();
          int xx[4] = {re1+1,re1-1,re1,re1};
          int yy[4] = {re2,re2,re2+1,re2-1};
          for (int i=0;i<4;i++){
            int x = xx[i];
            int y = yy[i];
            if (x >= 0 && y >= 0 && x < h && y < w){
              cout << d[x][y] << " " << visited[x][y] << " "<< x << " " << y << endl;
              if (d[x][y] == '*' && visited[x][y] == false){
                cout << x << " " << y << endl;
                visited[x][y] = true;
                xpos.push(x);
                ypos.push(y);
              }

            }

          }


          xpos.pop();
          ypos.pop();
        }
        if (maxi<counter){
          cout << "aa";
          maxi = counter;
          }
        }
      }
    }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cout<<visited[i][j] ;
    }
    cout << endl;
  }
  cout << maxi-1;
}

int main(){
  solve();
}
