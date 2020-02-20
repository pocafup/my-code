#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

typedef priority_queue<pair<int,int> > pq;

int a,b;
int pos[101];
vector<int> vec;
vector<pair<int,int> > vec2;
bool sorted(pair<int,int> aa, pair<int,int> bb){
  if (aa.second!=bb.second) return aa.first<bb.first;
  else return aa.second>bb.second;
}
int gang(int start, int num){
  pq q;
  int ans=0;
  int re = vec[0];
  if(start==-1 && num == -1){
    for (int i=1;i<vec.size();i++){
      if(vec[i]!=0) q.push(make_pair(vec[i],i));
    }
  }else{
    for (int i=1;i<vec.size();i++){
      if (i!=num && i!=start) q.push(make_pair(vec[i],i));
      else if(num!=start) q.push(make_pair(vec[i]-1,i));
      else q.push(make_pair(vec[i]-2,i));
    }
    if (start == 0 ) re--;
    if (num == 0) re--;

  }
  while(q.size()>=2){
    int qf = q.top().first-1;
    int qs = q.top().second;
    q.pop();
    int qf2 = q.top().first-1;
    int qs2 = q.top().second;
    q.pop();
    if(qf>0)q.push(make_pair(qf,qs));
    if(qf2>0)q.push(make_pair(qf2,qs2));
  }
  // cout << q.top().first << endl;
  ans = re;
  // cout << ans << endl;
  if (q.size()==1){
    ans -= q.top().first;
  }
  return ans;
}

int main(){
  cin >> a >> b;
  for (int i=0;i<b;i++) {cin >> pos[i];vec.push_back(pos[i]);}
  //pq aa;
  int cc = gang(-1,-1);
  // cout << "   " << gang(0,2) << endl;
  if (cc>0) {
    cout << "YES" << endl << cc << endl;
    int st = -1;
    bool update = true;
    int sc = 0;
    int kk = 0;
    for (int i=0;i<b;i++) vec2.push_back(make_pair(i,vec[i]));

    sort(vec2.begin(),vec2.end(),sorted);
    // for (int i=0;i<b;i++){
    //   for (int j=0;j<b;j++){
    //     if (vec)
    //   }
    // }
    // for (int j=0;j<vec2.size();j++) cout << vec2[j].first << " " << vec2[j].second << endl;

    while(update){
      // vector<pair<int,int> > temp;
      // swap(temp,vec2);
      sc = 0;
      kk = 0;
      update = false;
      //cout << endl;
      //for (int j=0;j<vec2.size();j++) cout << vec2[j].first << " " << vec2[j].second << endl;
      //cout << endl;
      for (int i=0;i<b;i++){
        bool n =false;
        for (int j=0;j<b;j++){
          int po1 = vec2[i].first;
          int po2 = vec2[j].first;
          if (gang(po1,po2)==cc && vec[po1]>0 && vec[po2]>0){
            if (po1!=po2 || (po1==po2 && vec[po1]-2>=0)){
              update = true;
              vec[po1]--;
              vec[po2]--;
              // cout << po1+1 <<endl << po2+1 << endl;
              n = true;
              break;
            }

          }
        }

        if (n) break;
      }
      for (int j=0;j<vec.size();j++){
        // cout << vec[j] << " ";
        if (vec[j]>0) {sc++;kk+=vec[j];}

      }
      if (sc==1){
        while(vec[0]>0) {cout << 1 << endl;vec[0]--;}
      }
      // cout << endl;
    }

  }else{
    cout << "NO";
  }
}
