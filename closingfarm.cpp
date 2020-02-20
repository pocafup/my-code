#include <iostream>
#include <algorithm>

using namespace std;

int par[200002];
int find(int aa){
  return par[aa] == aa ? aa : par[aa] = find(par[aa]);
}
void uni(int aa,int bb){
  aa = find(aa);
  bb = find(bb);
  par[aa] = bb;
}
pair<int,int> farm[200002];
int seq[200002];
bool num[200005];
int main(){
  int a,b; cin >> a >> b;
  for (int i=1;i<=a;i++) par[i] = i;
  for (int i=1;i<=a;i++) cout << par[i] << endl;
  for (int i=0;i<b;i++){
    cin >> farm[i].first >> farm[i].second;
    uni(farm[i].first,farm[i].second);
  }
  for (int i=0;i<a;i++) cin >> seq[i];
  for (int i=1;i<=a;i++) cout << par[i] << endl;
  for (int i=0;i<a;i++){
    num[i] = true;
    if(find(seq[i]) != seq[i] && num[find(seq[i])]==false) cout << "YES" << endl;

    else if (find(seq[i]) != seq[i]){
      //bool n = true;
      int ee = seq[i];
      while(find(ee)!=ee){
        if (num[find(ee)] == false) {
          cout << "NO" << endl;
          break;
        }else{
          ee = find(ee);
        }
      }
    }else{
      cout << "NO" << endl;
    }
  }
}
