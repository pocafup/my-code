#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int decimalToOctal(int decimalNumber)
{
    int rem, i = 1, octalNumber = 0;
    while (decimalNumber != 0)
    {
        rem = decimalNumber % 8;
        decimalNumber /= 8;
        octalNumber += rem * i;
        i *= 10;
    }
    return octalNumber;
}

int main(){
  string a;
  getline(cin,a);
  int b[4*a.length()];
  memset(b,0,sizeof(b));
  int ans = 0;
  for (int i=0;i<a.length();i++){
    int temp = 0;
    if (a[i] == 'A' or a[i] == 'a'){
      temp = 10;
    }else if (a[i] == 'B' or a[i] == 'b'){
      temp = 11;
    }else if (a[i] == 'C' or a[i] == 'c'){
      temp = 12;
    }else if (a[i] == 'D' or a[i] == 'd'){
      temp = 13;
    }else if (a[i] == 'E' or a[i] == 'e'){
      temp = 14;
    }else if (a[i] == 'F' or a[i] == 'f'){
      temp = 15;
    }else{
      temp = a[i]-48;
    }
    ans = ans*16+temp;
  }
  cout << decimalToOctal(ans);
}
