#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;
vector<int> vec[100001];
int pos[100001];
bool vis[100001];
int a;
int next_empty(int posi){
  while(vis[posi]) {posi++; if (posi>=a) break;}
  // cout << posi << endl;
  return posi;
}
int main(){
  ifstream cin ("abcdd.in");
  cin >> a;
  for (int i=0;i<a;i++) {cin >> pos[i];vec[pos[i]].push_back(i);}
  bool update = true;
  int po,re = 0;
  int loop = 0;
  while(update){
    loop++;
    update = false;
    while(vis[re]){re++;if (re>=a) break;}
    if (re>=a)break;
    update = true;
    po = re;
    int next = 0;
    for (int i=0;i<vec[pos[po]].size();i++) {vis[vec[pos[po]][i]] = true;next = vec[pos[po]][i];}
    // po = vec[po][vec[po].size()-1];
    // cout << "next = " << next << endl;
    while(po<a){
      po = next_empty(next);
      // cout << "po = " << po << endl;
      if (po>=a) break;
      // cout << po;
      for (int i=0;i<vec[pos[po]].size();i++) {vis[vec[pos[po]][i]] = true;next = vec[pos[po]][i];}
    }
  }
  cout << loop-1;

}
