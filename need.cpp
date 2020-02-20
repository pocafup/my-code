#include <iostream>
#include <vector>

using namespace std;

void solve(){
  vector<int> x;
  vector<int> re;
  int a,b,c;
  int count;

  int count2[1000];
  memset(count2,0,sizeof(count2));
  int ans;
  cin >> a >> b >> c;
  float maxi = 1.0*a/b;
  int d[1000][1000];
  for(int i=0;i<c;i++){
    cin >> d[i][0] >> d[i][1];
  }
  for(int i=0;i<(1<<c);i++){
    int time1 = a;
    int time2 = b;
    for(int j=0;j<c;j++){
      int temp = i>>j;
      if(temp & 1){
        time1 += d[j][0];
        time2 += d[j][1];
        x.push_back(j);



        }

        }
        if (1.0*time1/(time2)>maxi){
          maxi = time1/time2;
          ans = i;

      }
      x.clear();

  }
  for (int i=0;i<c;i++){
    if((ans>>i)&1){
      cout << i+1 << endl;
    }
  }
  if (ans == 0){
    cout << "NONE";
  }



}

int main(){
  solve();
}
