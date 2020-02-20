#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point{
  int x,y;
};
int a;
bool ccw(point aa, point bb, point cc){
  bool d = (bb.x-aa.x)*(cc.y-aa.y)-(bb.y-aa.y)*(cc.x-aa.x)>=0;
  return d;
}
vector<point> convec(vector<point> vec,bool up){
  vector<point> vec2;
  point l1 = vec[0];
  point l2 = vec[1];
  int temp1 = 0,temp2 = 1,temp3 = 2;
  point l3 = vec[2];
  vec2.push_back(l1);
  while(temp1!=a){
    if (ccw(l1,l2,l3)==up){
      temp2 = temp3;
      temp3++;
      l1 = vec[temp1];
      l2 = vec[temp2];
      l3 = vec[temp3];
    }else{
      temp1 = temp2;
      temp2 = temp3;
      temp3++;
      l1 = vec[temp1];
      l2 = vec[temp2];
      l3 = vec[temp3];
      vec2.push_back(l1);

    }
    return vec2;
  }
}
pair<int,int> team1[50001],team2[50001];
vector<point> t1up,t1dw,t2up,t2dw;
vector<point> a1up,a1dw,a2up,a2dw;
int main(){
  cin >> a;
  for (int i=0;i<a;i++) cin >> team1[i].first >> team1[i].second;
  for (int i=0;i<a;i++) cin >> team2[i].first >> team2[i].second;
  sort(team1,team1+a);
  sort(team2,team2+a);
  for (int i=0;i<a;i++){
    point t1,t2;
    t1.x = team1[i].first;
    t1.y = team1[i].second;
    t2.x = team2[i].first;
    t2.y = team2[i].second;
    cout << t1.x <<"     " << t1.y << endl;
    t1up.push_back(t1);
    t1dw.push_back(t1);
    t2up.push_back(t2);
    t2dw.push_back(t2);
  }
  a1up = convec(t1up,true);
  a1dw = convec(t1dw,false);
  // l1 = t1dw[0];
  // l2 = t1dw[1];
  // temp1 = 0,temp2 = 1,temp3 = 2;
  // l3 = t1dw[2];
  // a1dw.push_back(l1);
  // while(temp2!=a){
  //
  //   if (!ccw(l1,l2,l3)){
  //     temp2 = temp3;
  //     temp3++;
  //     l1 = t1dw[temp1];
  //     l2 = t1dw[temp2];
  //     l3 = t1dw[temp3];
  //   }else{
  //     //cout << "aa" << endl;
  //     temp1 = temp2;
  //     temp2 = temp3;
  //     temp3++;
  //     l1 = t1dw[temp1];
  //     l2 = t1dw[temp2];
  //     l3 = t1dw[temp3];
  //     a1dw.push_back(l1);
  //
  //   }
  // }
  for (int i=0;i<a1up.size();i++) cout << a1up[i].x << " " << a1up[i].y << endl;
  for (int i=0;i<a1dw.size();i++) cout << a1dw[i].x << " " << a1dw[i].y << endl;
}
