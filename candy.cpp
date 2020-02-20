#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int eat[51];
int pos[200];
int size[40001];
int main(){
  int a,b,c,d; cin >> a >> b >> c >> d;
  for (int i=0;i<b;i++) cin >> eat[i];
  for (int i=0;i<c;i++) cin >> pos[i];
  queue<pair<int,int> > q;
  q.push(make_pair(a,0));
  int maxi = 0;
  int loop = 500000;
  while(!q.empty()){
    loop --;
    if (loop==0) {cout << -1; exit(0);}
    int qf = q.front().first;
    int qs = q.front().second;
    q.pop();
    for (int i=0;i<c;i++){
      if (qf == pos[i]){
        if (qf!=a){
          q.push(make_pair(qf+d,qs));
        }
      }
    }
    for (int k=0;k<b;k++){
      for (int i=0;i<c;i++){
        if (qf-eat[k]==pos[i]){
          if (size[qf-eat[k]+d]<qs+eat[k]){
            size[qf-eat[k]+d]=qs+eat[k];
            q.push(make_pair(qf-eat[k]+d,qs+eat[k]));
          }
        }
      }
      if (qf-eat[k] > 0){
        if (size[qf-eat[k]]<qs+eat[k]){
          size[qf-eat[k]] = qs+eat[k];
          q.push(make_pair(qf-eat[k],qs+eat[k]));
        }
      }else if (qf-eat[k] == 0){
        maxi = max(maxi,qs+eat[k]);
      }else{
        maxi = max(maxi,qs);
      }
    }
  }
  cout << maxi;
}
