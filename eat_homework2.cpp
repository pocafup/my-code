/*
ID:dx424391
PROG: homework
LANG:C++
*/
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int arr[100001];
int mini[100001];
double sum[100001];
int main(){
  ifstream cin ("homework.in");
  ofstream cout("homework.out");
  int a; cin >> a;
  double greedy = 0;
  for (int i=0;i<a;i++){
    cin >> arr[i];
    greedy+=arr[i];
  }
  mini[a-1] = arr[a-1];
  double maxi = 0;
  for (int i=a-2;i>=0;i--)mini[i] = min(arr[i],mini[i+1]);
  for (int i=0;i<a-2;i++){
    greedy-=arr[i];
    sum[i] = (greedy-mini[i])/(a-i-2);
    // if (sum[i]>maxi) cout << su m[i] << endl;
    maxi = max(maxi,sum[i]);

    // cout << sum[i] << endl;
  }
  for (int i=0;i<a;i++) if (sum[i] == maxi) cout << i+1<< endl;
}
