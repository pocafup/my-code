#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a,b; cin >> a >> b;
  pair<int,int> c[a];
  for (int i=0;i<a;i++){
    cin >> c[i].first >> c[i].second;
  }
  int count = 0;
  int visited[a];
  memset(visited,false,sizeof(visited));
  int pos = 0;
  int end = 1;
  while(end<a){
    if (c[pos].first+c[pos].second*b>=c[end].first+c[end].second*b){
      end++;
    }else{
      pos++;
      if (pos == end){
        count++;
        end++;
      }
    }
  }
  cout << count;
}
