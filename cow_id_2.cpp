#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int index_at = 1;
int index_end = 0;
int arr[100050];
int main(){
  int a,b; cin >> a >> b;
  index_end = b;
  for (int i=0;i<b;i++) arr[i]=1;
  int fir = 1;
  if (fir == a) {for (int i=0;i<index_end;i++) cout << arr[i]; return 0;}
  if (b == 1){
    cout << 1;
    for (int i=0;i<a-1;i++) cout << 0;
    return 0;
  }

  while(fir!=a){
    arr[index_end] = 1;
    arr[index_at] = 0;

    fir++;
    int temp[100050];

    memset(temp,0,sizeof(temp));
    if (fir == a) {for (int i=0;i<index_end;i++) {cout << arr[i];}break;}


    for (int i=0;i<=index_end;i++)temp[i] = arr[i];
    while(fir!=a && temp[0]!=0){
      fir++;
      next_permutation(temp,temp+index_end+1);
    }
    if (temp[0]==0 && fir==a) {
      temp[0]=1;temp[index_end]=0;
      for (int i=0;i<=index_end+2;i++) {cout << temp[i];}
      break;
    }
    if (fir == a) {for (int i=0;i<=index_end;i++) {cout << temp[i];}break;}
    fir--;
    index_at++;index_end++;

  }

}
