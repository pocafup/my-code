#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
// void setIO(string name) {
// 	// freopen((name+".in").c_str(),"r",stdin);
// 	// freopen((name+".out").c_str(),"w",stdout);
// 	ios_base::sync_with_stdio(0);
// }
int main(){
  // setIO("ABCDDDDD");
  ofstream cout ("abcdd22.out");
  for (int i=1;i<=(1<<);i++){
    int re = 0;
    for (int j=0;j<=30;j++){
      if ((i>>j)&1) re++;
    }
    cout << re << ",";
  }
}
