#include <iostream>
#include <vector>

using namespace std;

int a;
vector<char> moo;
vector<char> re ;
int recur_time = 0;
int re_num = 4;
int re_num2 = 3;
int n = 3;
void get_digit(){
  if (n<a){
    recur_time ++;
    n = n*2+re_num;
    re_num++;
    get_digit();
  }
}

void recur(){
  if(moo.size()<n){
    re = moo;
    moo.push_back('m');
    for(int i=0;i<re_num2;i++){
      moo.push_back('o');
    }
    re_num2++;
    for(int j=0;j<re.size();j++){
      moo.push_back(re[j]);
    }
    recur();
  }
}
int main(){
  moo.push_back('m');
  moo.push_back('o');
  moo.push_back('o');
  cin >> a;
  get_digit();
  recur();
  // for (int i=0;i<moo.size();i++){
  //   cout << moo[i];
  // }
  // cout << endl;
  cout << moo[a-1];
}
