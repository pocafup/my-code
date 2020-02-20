#include <iostream>
#include <algorithm>
#include <complex>

using namespace std;

typedef pair<double,double> pp;
#define x real()
#define y imag()
struct line{
  pp fir, sec;
  double slope;
}lin;
typedef complex<double> point;

// struct point{
//   double xcoor, ycoor;
// };
point getreflection(point P, point A, point B)
{
    point Pt = P-A;
    point Bt = B-A;

    point Pr = Pt/Bt;
    return conj(Pr)*Bt + A;
}
pp mid;
pp pos[1001];
bool visited[10001][10001];
int dis[1001][1001];
int e,f;
int main(){
  int a; cin >> a;
  for (int i=0;i<a;i++) {
    cin >> e >> f;
    visited[e][f] = true;
    pos[i].first = e;
    pos[i].second = f;
    mid.first += pos[i].first;
    mid.second += pos[i].second;
  }
  int ans = 0;
  int go = 0;
  for (int i=0;i<a;i++){
    bool n = false;
    lin.fir = pos[i];
    lin.sec = mid;
    lin.slope = -1/(mid.second-pos[i].second)/(mid.first-pos[i].first);
    //int c = mid.second-slope*mid.first;
    for (int j=0;j<a;j++){
      if (i!=a){
        point aa(pos[j].first,pos[j].second);
        point bb(lin.fir.first,lin.fir.second);
        point cc(lin.sec.first,lin.sec.second);
        point give = getreflection(aa,bb,cc);
        //cout << (int)give.x << " " << give.y << endl;
        if ((int)give.x>=0 && (int)give.y>=0){
          if (visited[(int)give.x][(int)give.y]==true){
            continue;
          }else{
            n = false;
            break;
          }
        }


      }
      if (!n) break;
    }
    if (n) ans ++;
  }

  cout << ans;
}
