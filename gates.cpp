#include <iostream>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;
#define pp pair<int,int>
int n;
char order[1001];
bool vis[3005][3005];
bool onto[3005][3005][4];
int x[4] = {1,0,-1,0};
int y[4] = {0,-1,0,1};

char corr[4] = {'E','S','W','N'};
int main(){
  ifstream cin ("gates.in");
  ofstream cout ("gates.out");
  cin >> n;
  vis[1000][1000] = true;
  int ans = 0;
  pp curr = make_pair(1000,1000);
  for(int i=0;i<n;i++) {
    cin >> order[i];

    for (int j=0;j<4;j++){
      if (order[i]==corr[j]){
        onto[curr.first][curr.second][(j+2)%4] = true;
        curr.first+=x[j];
        curr.second+=y[j];
        if (vis[curr.first][curr.second] == true && onto[curr.first][curr.second][j] != true) ans++;
        vis[curr.first][curr.second] = true;

        onto[curr.first][curr.second][j] = true;
      }
    }
  }
  cout << ans;
}
