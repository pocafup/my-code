#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int> > vec;
vector<int> memory;
int grid[101][101];
int vis[101];

int a,b;
int dfs(int num, int curr, int pa){
  if (curr == pa) return 0;
  int my = 0;
  vis[num] = true;
  for (int i=0;i<b;i++){
    if (!vis[i]){
      // int dp_able = 0;

      // for (int j=0;j<vec.size();j++){
      //   bool test = true;
      //   for (int k=0;k<vec[j].size();k++){
      //     if (vec[j][k]!=vis[k]) {test = false; break;}
      //   }
      //   if (test) {dp_able = j;break;}
      // }
      // if (dp_able>0) my = memory[dp_able];
      // else {
      my = max(my,dfs(i,curr+1,pa)+grid[curr][i]);
      //   vector<int> temp;
      //   for (int j=0;j<b;j++) temp.push_back(vis[j]);
      //   vec.push_back(temp);
      //   memory.push_back(my);

    }
  }
  vis[num] = false;
  //if (curr == 0) cout << my << endl;
  return my;
}
int main(){
  cin >> a >> b;
  for (int i=0;i<a;i++)
    for (int j=0;j<b;j++)
      cin >> grid[i][j];
  int maxi = 0;
  for (int i=0;i<b;i++){
    maxi = max(maxi,dfs(i,0,a));
  }
  cout << maxi;
}
