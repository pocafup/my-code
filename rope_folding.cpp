#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool t = false;
vector<int> cd;
int main(){
  int a,b;
  cin >> a >> b;
  int c[a];
  for (int i=0;i<a;i++){
    cin >> c[i];
    c[i] = c[i]*2;
  }
  sort(c,c+a);
  for (int i=0;i<a;i++){
    cout << c[i] << endl;
  }
  for(int i=1;i<a;i++){
    int e;
    e = min(i,a-i-1);
    for(int j=i-e;j<i+e;j++){
        int dis = (c[j]+c[i])/2;
        int va = c[i];
        int vb = c[j];
        cout << va << " " << vb << " " << dis << "  aa"<< endl;

        if (va != vb){
          t = true;
          bool n = true;
          int re = 1;
          while (i+re <= a && j-re >= 0 && t == true && n == true ){
            if (abs(va-dis) != abs(vb-dis)){
              t = false;
            }else if(i+re < a && j-re > 0 ){
              va = c[i+re];
              vb = c[j-re];
              re++;
              cout << va << " " << vb << " " << dis << endl;
            }else{
              n = false;
            }
          }
        }else{
          t = false;
        }
        cout << va << " " << vb << " " << dis << endl;

        if (t && abs(va-dis) == abs(vb-dis)){
          bool x = true;
          for (int z=0;z<cd.size();z++){
            if (cd[z] == dis){
              x = false;
            }
          }
          if (x){
            cd.push_back(dis);
          }
          t = false;
        }

    }
    for(int j=i+1;j<i+e+1;j++){
      int dis = (c[j]+c[i])/2;
      int va = c[i];
      int vb = c[i+1];
      cout << va << " " << vb << " " << dis << "  aa"<< endl;

      if (va != vb){
        t = true;
        bool n = false;
        int re = 1;
        while (i-re >= 0 && j+re <= a && t == true ){
          n = true;
          if (abs(va-dis) != abs(vb-dis)){
            t = false;
          }else if(i-re > 0 && j+re < a){
            va = c[i-re];
            vb = c[j+re];
            re++;
            cout << va << " " << vb << " " << dis << endl;
          }else{
            n = false;
            break;
          }
        }

      }else{
        t = false;
      }
      cout << va << " " << vb << " " << dis << endl;

      if (t && abs(va-dis) == abs(vb-dis)){
        bool x = true;
        for (int z=0;z<cd.size();z++){
          if (cd[z] == dis){
            x = false;
          }
        }
        if (x){
          cd.push_back(dis);
        }
        t = false;
      }

    }



  }

  for (int z=0;z<cd.size();z++){
    cout << cd[z]/2 << endl;
  }
  cout << endl;
  cout << cd.size();
}
