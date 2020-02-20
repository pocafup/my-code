//
// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <set>
// #include <iterator>
//
// using namespace std;
//
// bool sorted(pair<int,int> aa, pair<int,int> bb) {return aa.second>bb.second;}
// int main(){
//   int a,b; cin >> a >> b;
//   pair<int,int> cor[a+2];
//   for (int i=0;i<a;i++) cin >> cor[i].first >> cor[i].second;
//   sort(cor,cor+a,sorted);
//   set<int> x;
//   int begin = 0;
//   int mini = 10000000;
//   //for (int i=0;i<a;i++) cout << cor[i].first << " " << cor[i].second << endl;
//   for (int i=0;i<a;){
//     if (cor[i].second-cor[begin].second >= b){
//       mini = min(abs(cor[i].first-cor[begin].first),mini);
//       i++;
//     }else{
//       begin++;
//     }
//   }
//   cout << mini;
//
// }

#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <iterator>

using namespace std;

bool sorted(pair<int,int> aa, pair<int,int> bb) {return aa.second<bb.second;}
int main(){
  int a,b; cin >> a >> b;
  pair<int,int> cor[a+2];
  for (int i=0;i<a;i++) cin >> cor[i].first >> cor[i].second;
  sort(cor,cor+a,sorted);
  set<int> x;
  int begin = 0;
  int mini = 10000000;
  for (int i=0;i<a;i++){
    while(cor[i].second-cor[begin].second>=b){
      //cout << cor[i].second << " " << cor[begin].second << endl;
      x.insert(cor[begin].first);
      begin++;
    }
    // cout << cor[i].first << " ae" << endl;
  //  for (auto i=x.begin();i!=x.end();i++) cout << *i << " ";
    // cout << endl;
    auto it = x.upper_bound(cor[i].first);

    if(it == x.begin()){
      continue;
    }

    it--;

   // cout << *it << endl;
    //cout << cor[i].first << " " << *it << endl;
    if (cor[i].first-*it>=0) mini = min(cor[i].first-*it,mini);
    // cout << mini << " asd" << endl;
    //cout << it << " " << mini << " " << cor[i].first << " " << it << endl;
  }
  (mini != 10000000) ? cout << mini : cout << -1;

}

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <set>
// #include <iterator>
//
// using namespace std;
//
// bool sorted(pair<int,int> aa, pair<int,int> bb) {return aa.second>bb.second;}
// int main(){
//   int a,b; cin >> a >> b;
//   pair<int,int> cor[a+2];
//   for (int i=0;i<a;i++) cin >> cor[i].first >> cor[i].second;
//   sort(cor,cor+a,sorted);
//   set<int> x;
//   int begin = 0;
//   int mini = 10000000;
//   //for (int i=0;i<a;i++) cout << cor[i].first << " " << cor[i].second << endl;
//   for (int i=0;i<a;){
//     if (cor[i].second-cor[begin].second >= b){
//       mini = min(abs(cor[i].first-cor[begin].first),mini);
//       i++;
//     }else{
//       begin++;
//     }
//   }
//   cout << mini;
//
// }
