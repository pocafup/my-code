#include <iostream>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <fstream>
using namespace std;
int pref[5005][5005];

void findTriplets(int arr[], int ed) {
  bool found = false;
  // int ans = 0;
  for (int i=0; i<ed-1; i++){
    unordered_set<int> s;
    for (int j=i+1; j<ed; j++){
      int x = -(arr[i] + arr[j]);
      if (s.find(x) != s.end()) pref[i][j+1]++;
      else s.insert(arr[j]);
    }
  }
  // return ans;
}

int n,arr[5005],q;
int main() {
  // ifstream cin ("desktop/2.in");
  cin >> n >> q;
  for (int i=0;i<n;i++) cin >> arr[i];
  findTriplets(arr,n-1);
  // for (int i=1;i<n;i++) pref[0][i]+=pref[0][i-1];
  for (int i=0;i<n;i++) cout << pref[0][i] << " ";
  cout << endl;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cout << pref[i][j] << " ";
    }
    cout << endl;
  }
  // for (int i=1;i<n;i++){
  //   for (int j=i+1;j<n;j++){
  //     pref[i][j] = pref[0][j]-pref[0][i];
  //   }
  // }
  for(int i = 0; i <n; i++) {
			for(int j = n-1; j > 0; j--) {
				pref[j-1][i] += pref[j][i];
			}
		}
  for (int i=0;i<q;i++){
    int a,b; cin >> a >> b;
    a--;b--;
    cout << pref[a][b] << endl;
    // cout << findTriplets(arr,a,b) << endl;
  }
}
