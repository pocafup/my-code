#include <iostream>
#include <vector>

using namespace std;

int a;
bool l = false;
int main(){
  cin >> a;
  int e[a];
  vector<int> c;
  for (int i=0;i<a;i++){
    cin >> e[i];
  }
  for (int i=0;i<a;i++){
    for (int j=i;j<a;j++){
      if (e[i] < e[j]){
        cout << e[i] << " " << e[j] << endl;
        cout << i << " " << j << "  aa" << endl;
        c.insert(c.begin(),j+1);
        l = true;
        break;
      }
    }
    if (l==false){
      c.insert(c.begin(),0);
    }else{
      l = false;
      }
  }
  for (int i=c.size()-1;i>=0;i--){
    cout << c[i] << endl;
  }
}
