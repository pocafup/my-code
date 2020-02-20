#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
long long n;
struct Point{
  long long pos, sz;
  bool in;
};
vector<Point> vec;
vector<long long> rt;
Point mp(long long a, long long b, bool c){
  return (Point){a,b,c};
}
bool sorted(Point a, Point b){
  return a.pos<b.pos ||((a.pos==b.pos) && a.sz>b.sz);
}
void setIO(string name) {
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
	ios_base::sync_with_stdio(0);
}

int main(){
  setIO("mountains");
  cin >> n;
  for (long long i=0;i<n;i++){
    long long a,b; cin >> a >> b;
    a+=1e9;
    vec.push_back(mp(a-b,b,true));
    vec.push_back(mp(a+b,b,false));
  }
  sort(vec.begin(),vec.end(),sorted);
  long long x = -1, ans = 0;
  for (Point i : vec){
    // cout << i.pos-1e9 << "       " << i.sz << endl;
    if (i.pos+2*(i.sz*i.in)>x){
      x = i.pos+(2*i.sz*i.in);
      // cout << x-1e9 << endl;
      ans++;
    }
  }
  cout << ans << endl;

}
