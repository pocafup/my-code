#include <iostream>
#include <algorithm>

using namespace std;

pair<pair<int,int>,bool> pos[501];
int main(){
  int a; cin >> a;
  char bo;
  for (int i=0;i<a;i++) {
    cin >> pos[i].first.first >> pos[i].first.second >> bo;
    if (bo=='H') pos[i].second = true;
    else pos[i].second = true;
  }
  sort(pos,pos+a);
  bool n = true;
  for (int i=0;i<a;i++){
    for (int j=i+1;j<a;j++){
      n = false;
      int piff = pos[i].first.first;
      int pifs = pos[i].first.second;
      int pis = pos[i].second;
      int pjff = pos[j].first.first;
      int pjfs = pos[j].first.second;
      int pjs = pos[j].second;
      if (pjs!=pis) continue;
      for (int k=i+1;k<j;k++){
        int pkff = pos[k].first.first;
        int pkfs = pos[k].first.second;
        int pks = pos[k].second;
        if (pks!=pis){
          if (pkfs>=min(pjfs,pifs) && pkfs<=max(pjfs,pifs)) {n = true;continue;}

        }
      }
      if (n) continue;

    }
  }
}
