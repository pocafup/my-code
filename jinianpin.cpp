#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include <iostream>
#include <algorithm>

using namespace std;

bool dp[10001];
int num[10001][101];
int jinian[101];
int main(){
  for (int i=0;i<=100;i++) for (int j=0;j<10000;j++)num[j][i] = -1;
  int a,b,c; cin >> a >> b >> c;
  dp[c] = true;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> jinian[j];
    }
    for (int l=0;l<b;l++){
      for (int j=0;j<10000;j++){
        if (dp[j]){
          num[j%jinian[l]][l] = max(num[j%jinian[l]][l],j/jinian[l]);
        }
      }
    }
    for(int l=0;l<b;l++){
      for (int j=0;j<10000;j++){
        if (num[j][l]!=-1){
          // cout << num[j] << " " << j << endl;
          dp[j+num[j][l]*jinian[l]] = true;
        }
      }
    }
    for (int l=0;l<b;l++){
      for (int j=0;j<10000;j++){
        if (dp[j]){
          num[j%jinian[l]][l] = max(num[j%jinian[l]][l],j/jinian[l]);
        }
      }
    }

  }
    for (int j=10000;j>=0;j--)
      if (dp[j]) {cout << j; return 0;}


}
