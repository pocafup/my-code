#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
bool visited[1001];
bool vis[1001];
pair<int,int> in[50001];
pair< pair<int,int>, pair<int,int> > pos[50001]; //所有fence的起始点和结束点
pair<int,int> cows[50001];//奶牛的地点
bool check_two(pair<int,int> a, pair<int,int> b){
  return (a.first==b.first) || (a.second==b.second);
}
bool ccw(pp a, pp b, pp c) {
    return (b.first - a.first) * (c.second - a.second)
         > (b.second - a.second) * (c.first - a.first);
}
bool check(pair< pair<int,int>, pair<int,int> > fir, pair< pair<int,int>, pair<int,int> > sec){
  return ((fir.first.first == sec.first.first && fir.first.second == sec.first.second) ||
          (fir.second.first == sec.first.first && fir.second.second == sec.first.second)||
          (fir.first.first == sec.second.first && fir.first.second == sec.second.second) ||
          (fir.second.first == sec.second.first && fir.second.second == sec.second.second));
}//测试两个fence有没有共同点
int main(){
  int ans = 0;
  vector<pair< pair<int,int>, pair<int,int> > > vec[1000];//记录有几个群
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> in[i].first >> in[i].second;
  for (int i=0;i<b;i++)cin >> cows[i].first >> cows[i].second;
  //convex hull part
  int zz = 0;
  sort(in,in+a);
  stack<int> st;
  st.push(0);
  int curr = 1,pos = 2;
  while(pos!=a){
    while(st.size()>1){
      if (ccw(pt[st.top()],pt[curr],pt[pos])){
        curr = st.top();
        st.pop();
      }else break;
    }
    if (ccw(pt[st.top()],pt[curr],pt[pos])) curr = pos;
    else {
      st.push(curr);
      curr = pos;
    }
    pos++;
  }
  st.push(0);
  curr = 1,pos = 2;
  while(pos!=a){
    while(st.size()>1){
      if (!ccw(pt[st.top()],pt[curr],pt[pos])){
        curr = st.top();
        st.pop();
      }else break;
    }
    if (!ccw(pt[st.top()],pt[curr],pt[pos])) curr = pos;
    else {
      st.push(curr);
      curr = pos;
    }
    pos++;
  }

  cout <<zz << endl;
  vector<int> myvec[1001];
  for (int i=0;i<b;i++){
    for (int j=0;j<zz;j++){
      int edge = 0; //设置碰到的边缘为0
      for (int k=0;k<vec[j].size();k++){
        double x1 = vec[j][k].first.first;
        double y1 = vec[j][k].first.second;
        double x2 = vec[j][k].second.first;
        double y2 = vec[j][k].second.second;
        //这四行是为了找栅栏的起始点和终点
        //cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
        double cowx = cows[i].first;
        double cowy = cows[i].second;
        //奶牛的位置

        double slope = (y2-y1) / (x2-x1);//斜率
        bool cond1 = x1<=cowx && cowx<x2;
        bool cond2 = x2<=cowx && cowx<x1;
        // if (cowx == 1 && cowy == 1) cout << slope << "  " << cond1 << " " << cond2 << endl;
        bool above1 = (cowy >= slope * (cowx-x1) + y1); //测试奶牛是否在栅栏之上
        bool above2 = (slope>1e8) && (cowy>y1||cowy>y2);
        if ((cond1^cond2) && (above1||above2) ) edge++;//如果奶牛位置在两栅栏之间，并且在栅栏之上，输出
      }
      if (edge % 2 !=0){
        ans++;
      }
    }
  }

  cout << ans;
}
