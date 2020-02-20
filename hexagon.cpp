#include <iostream>
#include <queue>

using namespace std;

int main(){
  int a,b,c;

  int startx = 0, starty = 0;
  cin >> a >> b >> c;
  int e = 1;
  int x[6] = {-1,-1,0,0,1,1};
  int y[6] = {-1,0,-1,1,-1,0};
  pair<int,bool> d[a*2-1][a*2-1];
  int res[a*2-1];
  for (int i=0;i<a;i++){
    int f = a+i;
    res[i] = f;
    for (int j=0;j<f;j++){
      d[i][j].first = e;
      if (d[i][j].first == b){
        d[i][j].second = true;
        startx = i;
        starty = j;
      }else{
        d[i][j].second = false;
      }
      e++;
    }
  }
  for(int i=a;i<2*a-1;i++){
    int f = 2*a-i+a-2;
    for (int j=0;j<f;j++){
      d[i][j].first = e;
      if (d[i][j].first == b){
        d[i][j].second = true;
        startx = i;
        starty = j;
      }else{
        d[i][j].second = false;
      }
      e++;
    }
  }
  for (int i=0;i<a;i++){
    int f = a+i;
    for (int j=0;j<f;j++){
      cout << d[i][j].first << " ";
    }
    cout << endl;
  }
  for(int i=a;i<2*a-1;i++){
    int f = 2*a-i+a-2;
    for (int j=0;j<f;j++){
      cout << d[i][j].first<<" ";

    }
    cout << endl;
  }
  cout << startx << " " << starty << endl;
  for (int i=0;i<6;i++){
    if(startx+x[i]>=0 && startx+x[i]Y )

  }

}
