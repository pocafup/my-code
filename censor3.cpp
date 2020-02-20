#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
#include <vector>

using namespace std;
const int mod = 1e6+7;
const int d = 256;
int modInverse(int a, int m)
{
    a = a%m;
    for (int x=1; x<m; x++)
       if ((a*x) % m == 1)
          return x;
    return 0;
}
int power(int aa,int bb){
  int cc = 1;
  for(int i=0;i<bb;i++){
    cc = (cc*aa)%mod;
  }
  return  cc;
}
int main(){
  string a,b; cin >> a >> b;
  int save[a.length()];
  int currenthash=0;
  vector<char> out;
  int sum1,sum2;

  for (int i=0; i<b.length(); i++) {
    sum2 = (d*sum2 + (int)b[i]) % mod;
    sum1 = (d*sum1 + (int)a[i]) % mod;
  }

  int bad = 0;
  int running = power(256,b.length()-1);
  for (int i=0;i<a.length()-b.length();i++){
    out.push_back(a[i]);
    cout << sum1 << " " << sum2 << endl;
    // sum1 = (d*sum1 + (int)a[i]) % mod;
    sum1 = (d*(sum1-(int)a[i]*running) + (int)a[i+b.length()]) % mod;
    if (sum1<0) sum1+=mod;
    if (out.size()<b.length())currenthash++;
    else{

      if (sum1==sum2) bad = i;
      else currenthash++;
      if (sum1 == sum2) cout << "     " << sum1 << " " << sum2 << endl;
    }
    if (out.size() >=b.length() &&  currenthash==bad){
      out.pop_back();
      currenthash = save[out.size()];
      save[out.size()] = currenthash;
    }
  }
  for (int i=a.length()-b.length();i<a.length();i++) out.push_back(a[i]);
  for (int i=0;i<out.size();i++) cout << out[i];
}
