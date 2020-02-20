#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node{
  int start, end;
} N[100001],Q[100001];

int ans[100001][2];
vector<int> path[100001];
vector<int> path1[100001],path2[100001];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a-1;i++) cin >> N[i].start >> N[i].end;
  for (int i=0;i<b;i++) cin >> Q[i].start >> Q[i].end;
  for (int i=0;i<a;i++) {
    ans[i][0] = i;
    path[i].push_back(i);
  }
  for (int i=0;i<a;i++) {
    ans[N[i].end-1][0] = N[i].start-1;
    path[N[i].end-1].push_back(N[i].start-1);
  }
  bool update;
  update = true;
  while(update==true){
    update = false;
    for (int i=0;i<a;i++){
      //cout << ans[i][0] << " " << i << endl;
      if(ans[i][0]!=ans[ans[i][0]][0]){
        ans[i][1] = ans[ans[i][0]][0];
        path[i].push_back(ans[ans[i][0]][0]);
        update = true;
      }
    }
    for (int i=0;i<a;i++) ans[i][0] = ans[i][1];
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<path[i].size();j++){
      cout << path[i][j]+1 << " ";
    }
    cout << endl;
  }
  for (int i=0;i<b;i++){
    // cout <<"      " << Q[i].start-1 << " " << Q[i].end-1 << endl;

    int e = path[Q[i].start-1].size()-1;
    int f = path[Q[i].end-1].size()-1;
    // cout << e << "     " << f << endl;
    // cout << path[Q[i].start-1][e] << "  ee " << path[Q[i].end-1][f]<<endl;

    while(path[Q[i].start-1][e]==path[Q[i].end-1][f] && e>=0 && f>=0){

      e--;
      f--;
      // cout << path[Q[i].start-1][e] << "  ee " << path[Q[i].end-1][f]<<endl;

    }
    cout << e+f+2 << endl;
  }
  // for (int i=0;i<a;i++){
  //   for (int j=0;j<path[i].size();j++){
  //     cout << path[i][j] << " ";
    //   }
    //   cout << endl;
  // }
}
