#include <iostream>
#include <algorithm>
using namespace std;
int a,b;
bool visited[1000][1000];
int arrx[3],arry[3];
bool check_visit_corner(int fir, int sec){
  for (int i=0;i<3;i++) if (fir==arrx[i] && sec == arry[i]) return true;
  return false;
}
bool check_visit_x_edge(int fir){
  return fir==a || fir==0;
}
bool check_visit_y_edge(int sec){
  return sec==b || sec==0;
}
int main(){
  cin >> a >> b;
  arrx[0] = a;
  arrx[1] = a;
  arrx[2] = 0;
  arry[0] = 0;
  arry[1] = b;
  arry[2] = b;
  int x_move = 1, y_move = 1;
  int x = 1,y=1;
  while(!(check_visit_corner(x,y))){
    if (check_visit_x_edge(x)) x_move*=-1;
    if (check_visit_y_edge(y)) y_move*=-1;
    x+=x_move;
    y+=y_move;
  }
  string arr_ans[3] = {"top left","bottom right","top right"},ans;

  for (int i=0;i<3;i++){
    if (x==arrx[i] && y==arry[i]) ans = arr_ans[i];
  }
  cout << "The corner the ball will end up : " << ans << endl;
}
