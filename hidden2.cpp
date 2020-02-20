#include <iostream>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <vector>

using namespace std;

char pos[100001];
stack<char> st;
vector<pair<int,int> > se[2];

int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) cin >> pos[i];
  st.push('z');
  for (int i=0;i<a;i++) {
    if (pos[i]<st.top()){st.pop();se[0].clear();st.push(pos[i]);}
    if(pos[i]==st.top())se[0].push_back(make_pair(i,(i+1)%a));
  }
  int loop = 0;
  while(se[0].size()>1 && loop<=a){
    // cout << "aa" << endl;
    loop++;
    st.pop();
    st.push('z');
    for (int i=0;i<se[0].size();i++){
      int pf = se[0][i].first;
      int ps = se[0][i].second;
      if (pos[ps]<st.top()){
        st.pop();
        se[1].clear();
        st.push(pos[ps]);
      }
      // cout << pos[ps] << " " << st.top() << " " << ps << endl;
      // if(pos[ps]==st.top()) cout << "fef" << endl;
      if(pos[ps] == st.top()) se[1].push_back(make_pair(pf,(ps+1)%a));
    }
    // cout << endl;
    se[0].clear();
    for (int i=0;i<se[1].size();i++) se[0].push_back(se[1][i]);
    se[1].clear();

  }
  int ans = 1e8;
  for (int i=0;i<se[0].size();i++){
    ans = min(ans,se[0][i].first);
  }
  cout << ans;
  // for (int i=111;i<120;i++) cout << pos[i];
}
