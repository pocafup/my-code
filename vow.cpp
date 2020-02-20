#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string vowelss(string a, string b, string c){
    int ct1 = 0, ct2=0, ct3=0;
    string vowels = "AEIOUaeiou";
    for(int i=0;i<a.length();++i){
        if(vowels.find(a[i])!=-1){
            ct1++;
        }
    }
    for(int i=0;i<b.length();++i){
        if(vowels.find(b[i])!=-1){
            ct2++;
        }
    }
    for(int i=0;i<c.length();++i){
        if(vowels.find(c[i])!=-1){
            ct3++;
        }
    }

    if(ct1==ct2 && ct1==ct3 && ct2==ct3){
        return "Same number of vowels";
    }else{
      return "Not same number of vowels";
    }
}

int main(){
  string a,b,c;  cin >> a >> b >> c;
  cout << vowelss(a,b,c);

}
