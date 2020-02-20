#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
#define pp pair<int,int>
int n;
pp pos[100001];
int len = 0;
int x1[4] = {1,0,-1,0};
int y1[4] = {0,1,0,-1};
int x = 0, y = 0;
int dis(pp a, pp b){
  return abs(a.first-b.first)+abs(a.second-b.second);
}
int find_dis(int x2, int y2){
  int ans = 0;
  for (int i=0;i<n;i++) ans+=dis(make_pair(x2,y2),pos[i]);
  return ans;
}
int main(){
   cin >> n;
   set<pp> se;
   for (int i=0;i<n;i++) {cin >> pos[i].first >> pos[i].second;x+=pos[i].first; y+= pos[i].second;se.insert(pos[i]);}
   x/=n;y/=n;

   int mini_dist = find_dis(x,y);

   int count = 1;
   if (se.find(make_pair(x,y))!=se.end())count--;
   cout << mini_dist << " ";
   queue<pp> q;
   q.push(make_pair(x,y));
   se.insert(make_pair(x,y));
   // cout << find_dis(1,-1) << endl;
   while(!q.empty()){
     int qf = q.front().first;
     int qs = q.front().second;
     q.pop();
     for (int i=0;i<4;i++){
       // cout << find_dis(qf+x1[i],qs+y1[i]) << " " << mini_dist << " " << count << endl;

       if (find_dis(qf+x1[i],qs+y1[i])<mini_dist){count = 1;se.clear(); mini_dist = find_dis(qf+x1[i],qs+y1[i]);q.push(make_pair(qf+x1[i],qs+y1[i]));}
       if (find_dis(qf+x1[i],qs+y1[i])==mini_dist && se.find(make_pair(qf+x1[i],qs+y1[i]))==se.end()){
         count++;

         // cout << qf+x1[i] << " " << qs+y1[i] << " " << count << endl;
         // cout<< count << endl;
         se.insert(make_pair(qf+x1[i],qs+y1[i]));
         // cout << "count = " << count << endl;
         q.push(make_pair(qf+x1[i],qs+y1[i]));
       }
     }
   }
   cout << count;
}
