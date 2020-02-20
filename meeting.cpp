#include <iostream>
#include <algorithm>

using namespace std;
struct Cow{
  int x,w,vel;
  vector<double> colli;
}cow[50005];
bool sorted(Cow a, Cow b){
  return a.x<b.x;
}

int main(){
  int n,l; cin >> n >> l;
  int total = 0,temp = 0;
  cow[n] = (Cow){0,0,0};
  cow[n+1] = (Cow){0,0,0};
  for (int i=0;i<n;i++){
    cin >> cow[i].x >> cow[i].w >> cow[i].vel;
    total+=cow[i].w;
  }
  sort(cow,cow+n,sorted);
  int before = 0;
  for (int i=1;i<n;i++){
    if (cow[i].vel != cow[i+1].vel){
      int move = (cow[i+1].x-cow[i].x)/(cow[i].vel+cow[i+1].vel);
      cow[i].x += move;
      cow[i].colli.push_back(colli[colli.size()-1]+move);
      if (cow[i].x==5||cow[i].x==0)
    }

  }
}
