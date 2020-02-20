#include <iostream>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int dec_to_bin(int cc){
  int zz = 0;
  int now = 0;
  while(cc!=0){
    zz += cc%2*pow(10,now);
    now++;
    cc/=2;
  }
  return zz;
}
int pos[17];
int num[100000];
int main(){
  int a,b; cin >> a >> b;
  int curr = 0;
  queue<pair<int,int> > q;
  for (int i=0;i<a;i++) {
    cin >> pos[i];
    if (pos[i]) q.push(make_pair(pos[i],0));
  }
  int re = 0;

  for (int i=a-1;i>=0;i--){
    re += pos[a-i-1]*pow(10,i);
  }
  dec_to_bin(re);
  cout << re << endl;

  int loop = 0;
  while(!q.empty() && q.front().second<b){
    cout << " aa" << endl;
    int qf = q.front().first;
    int qs = q.front().second;
    q.pop();
    int temp;
    if (qs!=curr){
      curr++;
      for (int i=a-1;i>=0;i--){
        temp += pos[i]*pow(10,i);
      }
    }
    dec_to_bin(temp);
    if (temp==re){
      loop = qs;
      break;
    }
    if (qf+1<a) {
      pos[qf+1] = pos[qf+1] ? 0:1;
      q.push(make_pair(qf+1,qs+1));
    }
    else {
      pos[0] = pos[0] ? 0 : 1;
      q.push(make_pair(0,qs+1));
    }
  }
  re = 0;
  for (int i=a-1;i>=0;i--){
    re += pos[a-i-1]*pow(10,i);
  }
  cout << re << endl;
}
