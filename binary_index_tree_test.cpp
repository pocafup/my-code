#include <iostream>
#include <algorithm>

using namespace std;
int n,ft[100001];
pair<int,int> pos[100001];
void update(int x, int v){
  while(x<=n){
    ft[x] += v;
    x += (x&-x);
    cout << x << " " << ft[x] << " afk"<< endl;
  }
}
int query(int x){
  return x>0 ? ft[x+1]+query(x-(x&-x)) : 0;
}

int main(){
  cin >> n;
  for (int i=0;i<n;i++){
    int d; cin >> d;
    pos[i] = make_pair(d,i);
  }
  int ans = 0;
  sort(pos,pos+n);
  // cout << endl;
  // for (int i=0;i<n;i++) cout << pos[i].first << " "<<pos[i].second << endl;
  // cout << endl;
  for (int i=n-1;i>=0;i--){
    int left = query(pos[i-1].second+1);
    //cout << query(pos[n-1].second) << " " << query(pos[i].second) <<endl;
    int right = query(pos[n-1].second+1)-query(pos[i].second+1);
    //cout << "       " << pos[i].second << " "<< " "<< left << " " << right <<endl;
    if (max(left,right)>min(left,right)*2) ans++;
    //pdate(i+1,1);
    update(i+1,1);
  }
  //for (int i=0;i<n;i++) cout << ft[i] <<endl;
  cout << ans;
}
