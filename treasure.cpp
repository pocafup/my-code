#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[5001][2][2];
int main(){
  int a; cin >> a;
  int nums[a+1];
  for (int i=0;i<a;i++) cin >> nums[i];
  int prefix[a+1];
  prefix[0] = 0;
  for (int i=1;i<=a;i++) prefix[i] = prefix[i-1]+nums[i-1];
  for (int i=0;i<a;i++) dp[i][i][0] = nums[i];
  for (int i=2;i<=a;i++){
    for(int left=0;left+i-1<a;left++){
        int right = left+i-1;
        dp[left][(i+1)%2][0] = max(nums[left]+dp[left+1][(i+1)%2][1],nums[right]+dp[left][i%2][1]);
        dp[left][(i+1)%2][1] = prefix[right]-dp[left][(i+1)%2][0]-prefix[left];
    }

  }
  for (int i=2;i<=a;i++){
    for(int left=0;left+i-1<a;left++){
      cout << dp[left][i%2][0] << " ";
    }
    cout << endl;
  }
  for (int i=0;i<=a;i++){
    cout << dp[i][0][0] << " ";
  }
  cout << endl;
  for (int i=0;i<=a;i++){
    cout << dp[i][1][0] << " ";
  }
  for (int i=0;i<=a;i++){
    cout << dp[i][0][0] << " ";
  }
  cout << endl;
  for (int i=0;i<=a;i++){
    cout << dp[i][0][1] << " ";
  }
  cout << endl;
  cout << endl;
  for (int i=0;i<=a;i++){
    cout << dp[i][0][0] << " ";
  }
  cout << endl;
  for (int i=0;i<=a;i++){
    cout << dp[i][1][1] << " ";
  }
  cout << dp[0][1][0];
}
