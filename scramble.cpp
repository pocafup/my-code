#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  int a;
  cin >> a;
  string b[a];

  for (int i=0;i<a;i++){
    cin >> b[i];
  }
  pair<int,int> c[a];
  vector<int> fir;
  vector<int> sec;
  int alphamax[27];
  int alphamin[27];
  memset(alphamax,0,sizeof(alphamax));
  memset(alphamin,0,sizeof(alphamin));
  for (int i=0;i<a;i++){
    int maxi = 0;
    int mini = 100;
    for (int j=0;j<b[i].length();j++){
      maxi = max(maxi,int(b[i][j]-96));
      mini = min(mini,int(b[i][j]-96));
    }
    c[i].first = maxi;
    c[i].second = mini;

  //  cout << maxi << " "<< mini << " eeee" << endl;
    fir.push_back(maxi);
    sec.push_back(mini);

  }
  sort(fir.begin(),fir.end());
  sort(sec.begin(),sec.end());
  while(fir[0] == 0){
    fir.erase(fir.begin());
  }
  while(sec[0] == 0){
    sec.erase(sec.begin());
  }

  for (int i=0;i<fir.size();i++){
    alphamax[fir[i]]++;
  }
  for (int i=0;i<sec.size();i++){
    alphamin[sec[i]]++;
  }
  alphamax[1] = 1;
  alphamin[1] = 1;
  alphamax[2] = 1;
  alphamin[2] = 1;
  for (int i=2;i<27;i++){
    alphamax[i] += alphamax[i-1];
    alphamin[i] += alphamin[i-1];

  }
  for (int i=0;i<a;i++){
  //  cout << c[i].second << " " << alphamax[2] << endl;
    cout << alphamax[c[i].second] << " " << alphamin[c[i].first] << endl;
  }
}
