#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int times(long long num){
  long long res = 1;
  for (long long i=0;i<num;i++){
    res *= 10;
  }
  return res;
}

int get_digit(int num, int i){
  num = div(num,times(i));
  long long n = 100000000000;
  while (n>=10){
    if (num>n){
      num -= n;
    }else{
      n = n/10;
    }
  }
}
int main(){
  get_digit(23,1);
  string a;
  getline(cin,a);
  string b;
  while(getline(cin,b)){
    if (b.length() == a.length()){
      cout <<"aa" << endl;
      int c[b.length()];
      for (int i=0;i<b.length();i++){
        if (b[i] == 'A' or b[i] == 'B' or b[i] == 'C'){
          c[i] = 2;
        }else if (b[i] == 'D' or b[i] == 'E' or b[i] == 'F'){
          c[i] = 3;
        }else if (b[i] == 'G' or b[i] == 'H' or b[i] == 'I'){
          c[i] = 4;
          cout << "bb"<<endl;
        }else if (b[i] == 'J' or b[i] == 'K' or b[i] == 'L'){
          c[i] = 5;
        }else if (b[i] == 'M' or b[i] == 'N' or b[i] == 'O'){
          c[i] = 6;
        }else if (b[i] == 'P' or b[i] == 'R' or b[i] == 'S'){
          c[i] = 7;
        }else if (b[i] == 'T' or b[i] == 'U' or b[i] == 'V'){
          c[i] = 8;
        }else if (b[i] == 'W' or b[i] == 'X' or b[i] == 'Y'){
          c[i] = 9;
        }
      }
      bool t = true;
      int ee = stoi(a);
      for (int i=0;i<b.length();i++){


        if(c[i] != a[i]){
          cout << "e " << endl;
          t = false;
        }
      }
      if (t){
        for (int i=0;i<b.length();i++){
          cout << b[i];
        }
        cout << endl;
      }
    }
  }
}
