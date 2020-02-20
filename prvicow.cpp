#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int a; cin >> a;
  int b[a];
  for (int i=0;i<a;i++){
    cin >> b[i];
  }
  int consec = 0;
  int up = true;
  int count = 2;
  int maxi = 0;
  if (b[0]>b[1]){
    up = false;
  }else if(b[0] == b[1]){
    consec = 1;
  }
  for (int i=1;i<a-1;i++){
    //cout << count << " " << b[i] << " " << b[i+1] << " " << up << endl;
    if (b[i+1]<b[i] && up == true){
      up = false;
      count ++;
    }else if (b[i+1]>b[i] && up == false){
      up = true;
      maxi = max(maxi,count);
      //cout << count << endl;
      if (i>2){
          if (b[i-1] == b[i]){
            count = 2+consec;

          }else{
              count = 2;
          }
      }
      consec = 0;
    }else if (b[i+1]==b[i]){
      consec++;
      count ++;
    }else if (b[i+1]>b[i] && up == true){
      count ++;
      consec = 0;
    }else if (b[i+1]<b[i] && up == false){
      count ++;
      consec = 0;
    }
    maxi = max(maxi,count);
  }
  //maxi = max(maxi,count);
  cout << maxi;
}
