#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int graph[100000];
int branch[100000];
int main(){
  int a; cin >> a;
  pair<int,int> q[a];
  for (int i=1;i<a;i++) cin >> q[i].first >> q[i].second;
  sort(q,q+a);
  int maxi = 0;
  for (int i=1;i<=a;i++){
    if (q[i].first == q[i+1].first) break;
    branch[q[i].second]+= branch[q[i].first]== 0 ? 1:branch[q[i].first];
    maxi = max(maxi,branch[i]);

  }

  //for (int i=0;i<=a;i++) cout << branch[i] << " ";
  for (int i=0;i<=a;i++) if (branch[i] == maxi) cout << i << endl;
  //cout << maxi;
}
