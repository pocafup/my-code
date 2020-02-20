#include <iostream>
#include <algorithm>
using namespace std;

char grid[1001][1001];
int n;
void face(bool way){
  int temp[1001][1001];
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      temp[i][j] = grid[i][j];
  int times = 0,local_count = 0;
  while(times<20 && local_count!=1){
    local_count = 0;
    for(int i=0;i<n;i++){
      int count = 0;
      for (int j=0;j<n;j++){
        if (temp[i][j]== (way?'L':'R')) count++;
      }
      if (count>(double)n/2){

        for (int j=0;j<n;j++)temp[i][j] = (temp[i][j]=='R')?'L' :'R';
        // for (int i=0;i<n;i++){
        //   for (int j=0;j<n;j++){
        //     cout << (char)temp[i][j];
        //   }
        //   cout << endl;
        // }
        // cout << endl;
      }
    }
    for(int j=0;j<n;j++){
      int count = 0;
      for (int i=0;i<n;i++){
        if (temp[i][j]== (way?'L':'R')) count++;
      }
      if (count>(double)n/2){
        for (int i=0;i<n;i++)temp[i][j] = (temp[i][j]=='R')?'L' :'R';
        // for (int i=0;i<n;i++){
        //   for (int j=0;j<n;j++){
        //     cout << (char)temp[i][j];
        //   }
        //   cout << endl;
        // }
        // cout << endl;
      }
    }

    for (int k=0;k<n;k++){
      for (int l=0;l<n;l++){
        // cout << (char)temp[k][l];
        if (temp[k][l] == (way?'L':'R')) local_count++;
      }
      // cout << endl;
    }
    // cout<< endl << endl;
    times++;
  }
  if (local_count == 1){
    for (int i=0;i<n;i++){
      for (int j=0;j<n;j++){
        if (temp[i][j] == (way?'L':'R')){cout << i+1 << " " << j+1;exit(0);}
      }
    }
  }

}
int main(){
  cin >> n;
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin >> grid[i][j];
    }
  }
  face(0);
  face(1);
  cout << -1;
}
