#include <iostream>
#include <algorithm>

using namespace std;

pair<pair<int,int>,bool> pos[501];
int main(){
  int a; cin >> a;
  char bo;
  for (int i=0;i<a;i++) {
    cin >> pos[i].first.first >> pos[i].first.second >> bo;
    if (bo=='H') pos[i].second = false;
    else pos[i].second = true;
  }
  sort(pos,pos+a);

  int ans1 = 1,ans2 = 1e8;

  for (int i=0;i<a;i++){
    for (int j=i;j<a;j++){
      int temp = 0;
      int high_bound = 1000;
      int piff = pos[i].first.first;
      int pifs = pos[i].first.second;
      int pis = pos[i].second;
      int low_bound = piff;
      int pjff = pos[j].first.first;
      int pjfs = pos[j].first.second;
      int pjs = pos[j].second;
      // bool n = false;
      if (pis==0 && pjs == 0){
        // for (int k=j;k>=i;k--){
        //   if (pos[k].second!=pis || pos[k].first.second<min(pifs,pjfs) || pos[k].first.second>max(pifs,pjfs)) n = true;
        // }
        // if (n) continue;
        if(temp>=ans1) {
          ans1 = temp;
          ans2 =  min(ans2,abs(piff-pjff)*abs(pifs-pjfs));
        }
        for (int k=j-1;k>=0;k--){
          int pkff = pos[k].first.first;
          int pkfs = pos[k].first.second;
          int pks = pos[k].second;
          if (pis==pks && pkfs>=min(pjfs,pifs) && pkfs<=max(pjfs,pifs)){
            temp++;
            low_bound = pkff;
            if(temp>ans1) {
              ans1 = temp;
              ans2 = abs(pkff-pjff)*abs(pifs-pjfs);
            }else if (temp==ans1){
              ans2 = min(ans2,abs(pkff-pjfs)*abs(pifs-pjfs));
            }
          }else if (pis!=pks && pkfs>=min(pjfs,pifs) && pkfs<=max(pjfs,pifs)){
            // for (int l=k-1;l>=0;l--){
            //   if (pkff == pos[l].first.first && pos[l].first.first>=min(pjfs,pifs) && pos[l].first.first<=max(pjfs,pifs)){
            //     if (pos[l].second == pis){
            //       if(temp>ans1) {
            //         ans1 = temp;
            //         ans2 = abs(pkff-low_bound)*abs(pifs-pjfs);
            //         cout << ans1 << " " << ans2  << endl;
            //       }else if (temp == ans1){
            //         cout << ans1 << " " << ans2  <<  endl;
            //         ans2 = min(ans2,abs(pkff-low_bound)*abs(pifs-pjfs));
            //       }
            //     }
            //   }else break;
            // }
          }
          break;
        }
        for (int k=j;k<a;k++){
          int pkff = pos[k].first.first;
          int pkfs = pos[k].first.second;
          int pks = pos[k].second;
          if (pis==pks && pkfs>=min(pjfs,pifs) && pkfs<=max(pjfs,pifs)){
            temp++;
            if(temp>ans1) {
              ans1 = temp;
              ans2 = abs(pkff-low_bound)*abs(pifs-pjfs);
            }else if (temp==ans1) ans2 = min(ans2,abs(pkff-low_bound)*abs(pifs-pjfs));
          }else if (pis!=pks && pkfs>=min(pjfs,pifs) && pkfs<=max(pjfs,pifs)){
            // for (int l=k+1;l<a;l++){
            //   if (pkff == pos[l].first.first && pos[l].first.first>=min(pjfs,pifs) && pos[l].first.first<=max(pjfs,pifs)){
            //     if (pos[l].second == pis){
            //       if(temp>ans1) {
            //         ans1 = temp;
            //         ans2 = abs(pkff-low_bound)*abs(pifs-pjfs);
            //         cout << ans1 << " " << ans2 << endl;
            //       }else if (temp == ans1){
            //         temp--;
            //         ans2 = min(ans2,abs(pkff-low_bound)*abs(pifs-pjfs));
            //         cout << ans1 << " " << ans2 << "t "<< endl;
            //         //temp--;
            //       }
            //     }
            //   }else break;
            // }

            break;
          }
        }

      }
      ans1 = max(ans1,temp);
    }
  }
  cout << ans1 << endl << ans2;
}
