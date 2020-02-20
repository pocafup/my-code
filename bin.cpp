#include <iostream>
#include <algorithm>

using namespace std;

string toBinary(int n)
{
    string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
int main(){
  for (int i=0;i<100;i++){
    string c = toBinary(i);
    for (int j=0;j<c.size();j++) cout << c[j];
    cout << "  "  << i << endl;
  }
}
