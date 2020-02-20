#include <iostream>
#include <queue>
using namespace std;

int a;
int b[20];
int k = 0;
int re[9];
int digit = 0;
int zz[9];
int pp = true;
int counte = 1;
bool tt;

int maxi = 0;
queue<int> q;
queue<int> p;
queue<int> re1;
queue<int> re2;

int find_digit(int aa,int cc, bool boll){
  if(boll){
    boll = false;
    digit = 0;
  }
  digit ++;
  if (aa<10){
    re[cc] = aa;
  }else{
    re[cc] = aa%10;
    find_digit(aa/10,cc+1,false);
  }
}

int main(){
  cin >> a;
  re1.push(0);
  re2.push(0);
  for (int i=0;i<a;i++){
    cin >> b[i];

    re1.push(b[i]);
    re2.push(b[i]);
  }
  p.push(q.front());
  q.pop();
  while (!re1.empty()){
    cout << "aa" << endl;
    re1.pop();
    re2.pop();
    while (!re1.empty()){
      p.push(re1.front());
      q.push(re2.front());
      re1.pop();
      re2.pop();
    }
    while (!q.empty()){

      find_digit(q.front(),0,true);
      for(int k=digit-1;k>=0;k--){
        zz[k] = re[k];
      }
      find_digit(p.front()+q.front(),0,true);
      cout<< p.front()+q.front() << "  aaa" << endl;
      for(int k=digit-1;k>=0;k--){
        cout << zz[k] << "   ee" << re[k] << endl;

        if (zz[k] > re[k]){

          tt = true;
        }
      }
      if(!tt){
        if (maxi<p.front()+q.front()){
          maxi = p.front()+q.front();

          counte ++;
        }
        q.push(p.front()+q.front());
        p.push(p.front()+q.front());
      }else{
        tt = false;
      }
      cout << q.front() << " "  << p.front()<<endl;
      re1.push(q.front());
      re2.push(p.front());
      q.pop();
      p.pop();
    }

  }
  cout << counte;

}
