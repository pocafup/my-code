#include <iostream>
#include <random>

using namespace std;
long long n,m,k,card[15][8];
//a means top, b means left
long long calc(long long y, long long x, bool a, bool b){
  if (a&&b) return ((x*(card[y][0]+1)+card[y][1])%m+m)%m;
  else if (a&&!b) return ((x*(card[y][2]+1)+card[y][3])%m+m)%m;
  else if (!a&&b) return ((x*(card[y][4]+1)+card[y][5])%m+m)%m;
  else return ((x*(card[y][6]+1)+card[y][7])%m+m)%m;
}
bool solve_and(long long,long long,bool);
bool solve_or(long long y, long long x){
  if (y==n) return x<=k || x+k>=m;
  bool mv = rand() & 1;
  return solve_and(y,x,mv) || solve_and(y,x,!mv);
}
bool solve_and(long long y, long long x, bool a){
  bool mv = rand()&1;
  // cout << "calc " << calc(y,x,a,mv) << " " << calc(y,x,a,!mv) << endl;
  return solve_or(y+1,calc(y,x,a,mv)) && solve_or(y+1,calc(y,x,a,!mv));
}
long long curr = 0;
string s;
void solve(){
  for (long long i=0;i<n;i++){
    // cout << "curr " << curr << endl;
    if (solve_and(i,curr,false)){
      cout << "B";
      // curr += max(calc(i,curr,false,false),calc(i,curr,false,true));
      curr= calc(i,curr,false,s[i]=='B');
    }else{
      cout << "T";
      // curr+=max(calc(i,curr,true,false),calc(i,curr,true,true));
      curr = calc(i,curr,true,s[i]=='B');
    }
  }
}
int main(){
  cin >> n >> m >> k;
  cin >> s;
  for (long long i=0;i<n;i++){
    for(long long j=0;j<8;j++) cin >> card[i][j];
  }
  solve();
}
