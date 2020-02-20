#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

pair<pair<int,int>,pair<int,int> > pos[1001];
int main(){
  int a,b,c; cin >> a >> b >> c;
  vector<pair<int,pair<int,int> > > vec;
  vector<pair<pair<int,int>,pair<int,int> > > y;
  vector<pair<int,int > > zz;
  for (int i=0;i<c;i++){
    cin >> pos[i].first.first >> pos[i].first.second >> pos[i].second.first >> pos[i].second.second;
    vec.push_back(make_pair(pos[i].first.first,make_pair(i,0)));
    vec.push_back(make_pair(pos[i].second.first,make_pair(i,1)));
  }
  sort(vec.begin(),vec.end());
  for (int i=0;i<vec.size();i++) cout << vec[i].first << " " << vec[i].second.first << endl;
  cout << endl;
  int ans = 0;
  int curr = 1;
  bool n = false;
  for (int i=0;i<c*2;i++){
    // for (int j=0;j<y.size();j++){
    //   cout << "       " << y[j].first << " " << y[j].second << endl;
    // }
    // cout << endl;
    if (!y.empty()){
      zz.clear();
      for (int j=0;j<y.size();j++){
        zz.push_back(make_pair(y[j].first.first,y[j].first.second));
        zz.push_back(make_pair(y[j].second.first,y[j].second.second));
      }

      sort(zz.begin(),zz.end());
      int sweep = 0,curr2 = zz[0].first;
      int cc = 1;
      for (int j=1;j<zz.size();j++){
        // cout << zz[j].first << " " << zz[j].second<< endl;
        if (cc>0){
          sweep += zz[j].first-curr2;
          curr2 = zz[j].first;
          cc+= (zz[j].second) ? 1 : -1;
        }else{
            cc += 1;
            curr2 = zz[j].first;
        }
      }
      int mul = (vec[i].second.second == 1) ?
      (i+1<a) ? (vec[i+1].first!=vec[i].first) ? vec[i].first-curr :
                vec[i].first-curr+1 : vec[i].first-curr+1 : 0;

      ans += mul*(sweep+1);
    //   cout << "     " << mul << " " << sweep << endl;
    //   cout << ans << endl;
      // cout << ans << " " << vec[i].first << " " << curr<< endl;
    }
    if (vec[i].second.second == 1){
      y.erase(y.begin());
    }else{
      y.push_back(make_pair(make_pair(pos[vec[i].second.first].first.second,0),
                            make_pair(pos[vec[i].second.first].second.second,1)));
    }
    curr = vec[i].first;
  }
  cout << ans;
}
