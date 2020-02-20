#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


struct node{
  int maxx,maxy,minx,miny;
}poi[26];

int alpha[26];
bool vis[26];
char grid[31][31];
vector<int> link[26];

using namespace std;
int count = 0;
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> grid[i][j];
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      if (grid[i][j]!='.'){
        if (!vis[(int)grid[i][j]-65]){
          vis[(int)grid[i][j]-65] = true;
          count ++;
        }
        poi[(int)grid[i][j]-65].maxx = max(i,maxx);
        poi[(int)grid[i][j]-65].minx = max(i,minx);
        poi[(int)grid[i][j]-65].miny = max(i,miny);
        poi[(int)grid[i][j]-65].maxy = max(i,maxy);
      }
    }

  }
  for (int i=0;i<)
}
