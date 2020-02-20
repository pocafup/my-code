#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long long digit = 0;
long long get_digit(long long num){
  if (num<10){
    digit++;
  }else{
    num = num/10;
    digit ++;
    get_digit(num);
  }
}

int times(long long num){
  long long res = 1;
  for (long long i=0;i<num;i++){
    res *= 10;
  }
  return res;
}
int main(){
  long long a ;
  cin >> a;
  get_digit(a);
  string b;
  string c[10];
  long long pos = 0;
  while(getline(cin,b)){
    if (b.length() == digit){
      //cout << b.length() << " " << digit << endl;
      long long re = 0;
      for (long long i=0;i<b.length();i++){
      //  cout << re << endl;
        if (b[i] == 'A' or b[i] == 'B' or b[i] == 'C'){
          re += 2*times(b.length()-i-1);
          cout << "aa";
        }else if (b[i] == 'D' or b[i] == 'E' or b[i] == 'F'){
          re += 3*times(b.length()-i-1);
        }else if (b[i] == 'G' or b[i] == 'H' or b[i] == 'I'){
          re += 4*times(b.length()-i-1);
        }else if (b[i] == 'J' or b[i] == 'K' or b[i] == 'L'){
          re += 5*times(b.length()-i-1);
        }else if (b[i] == 'M' or b[i] == 'N' or b[i] == 'O'){
          re += 6*times(b.length()-i-1);
        }else if (b[i] == 'P' or b[i] == 'R' or b[i] == 'S'){
          re += 7*times(b.length()-i-1);
        }else if (b[i] == 'T' or b[i] == 'U' or b[i] == 'V'){
          re += 8*times(b.length()-i-1);
        }else if (b[i] == 'W' or b[i] == 'X' or b[i] == 'Y'){
          re += 9*times(b.length()-i-1);
        }
      }
      //cout << re << endl;
      if (re == a){
        c[pos] = b;
        cout <<c[pos] << endl;
        pos ++;

      }
    }
  }
  //cout<<"YAY";
  for (long long i=0;i<pos;i++){
    cout << c[pos] << endl;
  }
}
