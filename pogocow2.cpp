#include <iostream>
#include <algorithm>


using namespace std;
int a;
pair<int,int> b[100000];

bool compare(pair<int,int> z, pair<int,int> zz){
  return z >zz;
}

int dfs(int aa,int current,int value,int dist){
  if (aa > a-1){
    return value;
  }else{
    if (abs(b[aa].first-b[current].first)<dist){
      return dfs(aa+1,current,value,dist);
    }else{
      return  max(dfs(aa+1,aa,value+b[aa].second,dist+abs(b[aa].first-b[current].first)),dfs(aa+1,current,value,dist));
    }
  }
}
int main(){

  cin >> a;

  for (int i=0;i<a;i++){
    cin >> b[i].first >> b[i].second;
  }
  sort(b,b+a);

  int m = dfs(0,0,0,0);
  sort(b,b+a,compare);
  m = max(m,dfs(0,0,0,0));
  // for (int i=0;i<a;i++){
  //   cout << b[i].first << " " << b[i].second << endl;
  // }
  cout << m;
}
