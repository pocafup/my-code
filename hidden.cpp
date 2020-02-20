#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool cmp(string aa,string bb){
  return aa.compare(bb)>0;
}
char st[100001];
int pos[100001];
string b;
unordered_set<string,greater<string> > se;
vector<string> vec;
char c;
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++){
    cin >> st[i];
  }
  string z;
  for (int i=0;i<a;i++) z[i] = 'z';

   for (int i=0;i<a;i++){
    for (int j=i;j<i+a;j++){
      b[j-i] = st[j%a];
    }
    cout << z.compare(b) << endl;
    if (b.compare(z)<0){
      z = b;
    }

  }

  for (int i=0;i<a;i++) cout << z[i];
}
