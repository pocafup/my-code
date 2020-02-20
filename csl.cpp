#include <iostream>
#include <algorithm>
using namespace std;

long long n,a[100001],ans,pa;

int main(){
  cin >> n;
  for (int i=0;i<n;i++) {cin >> a[i];ans+=a[i];}
  sort(a,a+n);
  for(int i=1;i<n;i++)if(a[i]==a[i-1])pa++;
  if(pa>1){cout << "cslnb";exit(0);}
  if(pa==1){
    for(int i=2;i<n;i++)if(a[i]==a[i-1]){
        if(a[i-2]==a[i-1]-1){cout << "cslnb";exit(0);}
        if(a[i]==0){cout << "cslnb";exit(0);}
    }
  }
  ans-=n*(n-1)/2;
  if(ans<=0)cout << "cslnb";
  else if(ans&1) cout << "sjfnb";
  else cout << "cslnb";
}
