#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> pq;
int n;
int main(){
  cin >> n;
  for (int i=0;i<n;i++){
    int a; cin >> a;
    if (a==1){
      int b; cin >> b;
      pq.push(-b);
    }else if (a==2){
      cout << -pq.top() << endl;
    }else pq.pop();
  }
}
