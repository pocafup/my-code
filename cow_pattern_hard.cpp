#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
#define logr = 1e9+7;
int nextB[100001],smaller[100001],smaller_equal[100001];
int pref[25];
int trouble[25001],cow[100001];
void add(int num, int amount){
  for (int i=num;i<25;i++) pref[i]+=amount;
}
int add_up(int num){
  int result = 0;
  for (int i=num;i>=0;i--) result+= pref[i];
  return result;
}
int main(){
  int a,b,c; cin >> a >> b >> c;
  for (int i=0;i<a;i++) cin >> trouble[i];
  for (int j=0;j<b;j++){
    cin >> cow[j];
    smaller[j] = pref[cow[j]-1];
    smaller_equal[j] = pref[cow[j]]+1;
    add(cow[j],1);
  }
  for (int i=0;i<b;i++) cout << smaller[i] << " ";
  cout << endl;
  for (int i=0;i<b;i++) cout << smaller_equal[i] << " ";
  cout << endl;
  memset(pref,0,sizeof(pref));
  //start KMP
  nextB[0] = -1;
  int cM = 0;
  for (int i=1;i<b;i++){
    while((cM>0&&(add_up(cow[i]-1)!=smaller[cM]||add_up(cow[i])!=smaller_equal[cM]))){
        for(int k=i-cM;k<=i-nextB[cM]-1;k++) add(cow[k],-1);
        cM=nextB[cM];
    }
    if(add_up(cow[i]-1)==smaller[cM]&&add_up(cow[i])==smaller_equal[cM]) cM++;
    nextB[i] = cM;

    add(cow[i],1);
    cout << cM << " ";

  }
  cout << endl;
  memset(pref,0,sizeof(pref));
  queue<int> q;
  cM = 0;
  for (int i=1;i<=a;i++){
    while(cM>0&&(add_up(trouble[i]-1)!=smaller[cM+1]||add_up(trouble[i])!=smaller_equal[cM+1])){
      for(int k=i-cM;k<=i-nextB[cM]-1;k++) add(trouble[k],-1);
      cM = nextB[cM];
    }
    if(add_up(trouble[i]-1)==smaller[cM+1]&&add_up(trouble[i])==smaller_equal[cM+1]) cM++;
    nextB[i]=cM;
    if(cM==a) q.push(i-a+1);

    add(trouble[i],1);

    cout << cM << " ";
  }
  cout << endl;
  cout << q.size() << endl;
  while(!q.empty()){
    cout << q.front() << endl;
    q.pop();
  }

}
