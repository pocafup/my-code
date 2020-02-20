#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int visited[20001];
vector<int> num[21];
int main(){
  int a; cin >> a;
  for (int i=0;i<20000;i++) visited[i] = 2*1e8;
  visited[1] = 1;
  int maxint = 1,turn = 1;

  while(visited[a]==2*1e8){
    turn++;
    maxint*=2;
    for (int i=maxint;i>=1;i--){
      if (visited[i]!=0){
        for(int j=1;j<i;j++){
          int other = i-j;
          cout << visited[i] << " " << visited[other] << endl;
          if (visited[i]!=visited[other]) visited[i] = min(visited[i],turn);
          else visited[i] = min(visited[i],max(visited[i],visited[other])+2);
        }
      }
    }
  }
  for (int i=0;i<=a;i++) cout << visited[i] << " ";
  cout << visited[a];
}
