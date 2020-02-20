#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
bool visited[1001];
bool vis[1001];
pair< pair<int,int>, pair<int,int> > pos[1001]; //所有fence的起始点和结束点
pair<int,int> cows[1001];//奶牛的地点
bool check(pair< pair<int,int>, pair<int,int> > fir, pair< pair<int,int>, pair<int,int> > sec){
  return ((fir.first.first == sec.first.first && fir.first.second == sec.first.second) ||
          (fir.second.first == sec.first.first && fir.second.second == sec.first.second)||
          (fir.first.first == sec.second.first && fir.first.second == sec.second.second) ||
          (fir.second.first == sec.second.first && fir.second.second == sec.second.second));
}//测试两个fence有没有共同点
int main(){
  vector<pair< pair<int,int>, pair<int,int> > > vec[1000];//记录有几个群
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++) cin >> pos[i].first.first >> pos[i].first.second >> pos[i].second.first >> pos[i].second.second;
  for (int i=0;i<b;i++)cin >> cows[i].first >> cows[i].second;
  int zz = 0;
  queue<int> q;
  //visited找没有经过的地点放进队列
  //如果遇到没有经过并且有相同点的地方就放入队列，并将visited改成true
  for (int i=0;i<a;i++){//测试每个点
    if (!visited[i]){
      visited[i] = true;
      vec[zz].push_back(pos[i]);
      q.push(i);
      while(!q.empty()){//当队列中有东西
        pair< pair<int,int>, pair<int,int> > temp1 = pos[q.front()];
        for (int j=0;j<a;j++){
          pair< pair<int,int>, pair<int,int> > temp2 = pos[j];
          if (!visited[j]){
            if (check(temp1,temp2)){//测试是否有共同点
                  q.push(j);
                  visited[j] = true;
                  vec[zz].push_back(pos[j]);
                }
            }
          }
          q.pop();
          //这里我拿掉了一行程序（反抄袭请谅解）
          //如果想填请认真看while里面缺什么。我相信会做这题的人都可以写的出来这行
      }
      zz++;//群数+1
    }
  }
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
        double cowx = cows[i].first;
        double cowy = cows[i].second;
        //奶牛的位置
        double slope = (y2-y1) / (x2-x1);//斜率
        bool cond1 = x1<=cowx && cowx<x2;
        bool cond2 = x2<=cowx && cowx<x1;
        //测试奶牛位置是否在两个栅栏的中间
        bool above1 = (cowy >= slope * (cowx-x1) + y1); //测试奶牛是否在栅栏之上
        if ((cond1^cond2) && above1) edge++;//如果奶牛位置在两栅栏之间，并且在栅栏之上，输出
      }
      if (edge % 2 !=0){
        myvec[i].push_back(j);//如果是奇数，说明奶牛在这个栅栏内
      }
    }
  }
  int ans = 1;//最小可能每只牛都是独立的
  for (int i=0;i<b;i++){//每只牛测试
    int num = 1;
    if (vis[i]) continue;
    vis[i] = true;
    for (int j=i;j<b;j++){
      if (myvec[i].size() == myvec[j].size() && i!=j &&!vis[j]){
        bool n = true;
        for (int k=0;k<myvec[i].size();k++) if (myvec[i][k]!=myvec[j][k]) n = false;
        if (n){
          num++;//如果两个奶牛在的族群数量相同，那么他们将会在同一族群内
          vis[j]=true;
        }
      }
    }
    ans = max(ans,num);//最大奶牛数
  }
  cout << ans;
}
