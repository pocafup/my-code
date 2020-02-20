#include <iostream>
#include <algorithm>

using namespace std;
pair<int,int> pos[50001];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<b;i++) cin >> pos[i].first >> pos[i].second;
  cout << endl << endl;
  pos[b] = make_pair(0,1);
  sort(pos,pos+b+1);
  int currs = 1;
  int ans = 0;
  for (int i=b-1;i>=0;i--){
    pos[i].second = min(pos[i].second,pos[i+1].second+(pos[i+1].first-pos[i].first));
  }
  for (int i=1;i<=b;i++){
    pos[i].second = min(pos[i].second,pos[i-1].second+(pos[i].first-pos[i-1].first));
  }
  for (int i=0;i<=b;i++) cout << pos[i].second << endl;
  for (int i=1;i<=b;i++){
    int increase = pos[i].second-currs;
    if (pos[i].first-pos[i-1].first<abs(increase)){
      currs += (increase>0) ? pos[i].first-pos[i-1].first : pos[i-1].first-pos[i].first;
      ans = max(currs,ans);
      //cout<< currs << endl;
    }else{
      //cout << increase << " incr" << endl;
      ans = max(ans,currs+increase+(pos[i].first-pos[i-1].first-abs(increase))/2);
      cout <<currs+increase+(pos[i].first-pos[i-1].first-abs(increase))/2 << endl;
      currs = pos[i].second;
      //cout << "       " <<  currs << endl;
    }

  }
  ans = max(ans,currs+a-pos[b].first);
  cout << ans;
}
