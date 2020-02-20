#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int N,K;
int nums[300001];

int main(){
   cin >> N >> K;
   // memset(nums,0,sizeof(nums));
   for (int i=0;i<N;i++) cin >> nums[i];
   sort(nums,nums+N);

   int left = 1;
   int dups = 0;
   for (int i=0;i<N-1;i++){
     dups++;
     if (nums[i]==nums[i+1]) continue;
     if (nums[i]+K<nums[i+1]) left += dups;
     dups = 0;
   }
   left += dups;
   cout << left;
}
