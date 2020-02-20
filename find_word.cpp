#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;
vector<string> vec;
string a;
bool vis[100001];
char shouldnot[6] = {',','.',';',':','?','!'};
bool check(int pos){
  for (int i=0;i<6;i++) if (vec[pos][vec[pos].length()-1]==shouldnot[i]) return true;
  return false;
}
int main(){
  cin >> a;
  while(!cin.eof()){
    vec.push_back(a); cin >> a;
  }
  for (int i=0;i<4;i++){
    srand (time(0));
    int choose = rand() % (vec.size()-1)  ;
    while(vec[choose].length()<5||vis[choose]||check(choose)) {

      srand (time(0));
      choose = rand() % (vec.size()-1);}
    // cout << vec[choose][vec[choose].length()-1] << endl;

    vis[choose] = true;
    cout << vec[choose] << endl;
  }
}
