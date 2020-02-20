// #include <algorithm>
// #include <vector>
// #include <utility>
//
// int main()
// {
//     typedef std::pair<int, double> myPair; // typedef to shorten the type name
//     std::vector <myPair> vec(5);
//
//     myPair low_val; // reference value (set this up as you want)
//     auto it = std::lower_bound(vec.begin(), vec.end(), low_val,
//         [](myPair lhs, myPair rhs) -> bool { return lhs.second < rhs.second; });
// }

#include <iostream>
#include <set>
#include <algorithm>
#include <utility>
#include <vector>
#define INF 20000000;
//
//
using namespace std;

int main(){
  set<pair<int,int> > se;
  se.insert(make_pair(5,7));
  se.insert(make_pair(15,7));
  set<pair<int,int> >::iterator it = se.upper_bound(make_pair(5,20000000));
  cout << (*it).first << " " << (*it).second << endl;
}
