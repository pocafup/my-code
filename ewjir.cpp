#include <iostream>
#include <algorithm>

using namespace std;
int prefix[100000],pos[100005];
int seg[100000];

int n,m;
int main(){
  cin >> n >> m;
  for (int i=0;i<n;i++) cin >> pos[i];
  prefix[0] = pos[0];
  for (int i=1;i<n;i++){
    prefix[i] = prefix[i-1]+pos[i];
  }
  for (int i=0;i<m;i++){
    int a,b; cin >> a >> b;
    int re = (a<2) ? 0 : prefix[a-2];
    cout << prefix[b-1]-re << endl;
  }
}

/*
O(n*m)
prefix sum:
input: O(n+m)
update: O(n)
worst case: O(n^2)
1 2 5 4 5
1 3 8 12 17

segment tree:

*/
