#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {

	int a,b; cin >> a >> b;
	int arr[a];
	for (int i=0;i<a;i++){
		cin >> arr[i];
	}

	int dp[a+1][b+1];
	memset(dp,0,sizeof(dp));
	for (int i=1;i<a+1;i++){
		for (int j=0;j<b+1;j++){
			if (j == 0){
				for (int z=1;z<i;z++){
					if (z<b+1){
						dp[i][j] = max(dp[i-1][j],max(dp[i][j],dp[i-z][z]));
					}
				}
			}else{
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]+arr[i-1]);
			}
		}
	}
	// for (int i=1;i<a+1;i++){
	// 	for (int j=0;j<b+1;j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << dp[a][0];
}
