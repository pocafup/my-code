#include <iostream>
#include <algorithm>

using namespace std;

int pos[50001];
int tracklist[50001];
int main(){
  int a,b; cin >> a >> b;
  for (int i=0;i<a;i++){
    cin >> pos[i];
  }
  int lower = 0, upper = 1e9;
  while(lower<upper-1){
    //cout << lower << " " << upper << endl;
    int mid = (upper-lower)/2+lower;
    int hap = 0;
    int pos2 = 0;
    bool work = true;
    for (int i=0;i<b;i++){
      while (hap<mid && pos2<a){
        hap += pos[pos2];
        pos2++;
      }
      if (hap<mid){
        work = false;
      }
      hap/=2;
    }
    if (work){
      lower = mid+1;
    }else{
      upper = mid;
    }
  }
  (lower==upper) ?  cout << lower-1  << endl : cout << lower << endl;
  int hap = 0;
  int pos2 = 0;
  for (int i=0;i<b;i++){
    while(hap<lower){
      hap +=pos[pos2];
      tracklist[pos2] = i;
      pos2++;
    }
    hap/=2;
  }
  for (int i=0;i<b;i++){
    cout << tracklist[i]+1 << endl;
  }
}




// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// int pos[50001];
// int tracklist[50001];
//
// int main(){
//   int hap = 0;
//   int pos2 = 0;
//   int a,b; cin >> a >> b;
//   for (int i=0;i<a;i++){
//     cin >> pos[i];
//   }
//   int lower = 0, upper = 1e9;
//   while(lower<upper-1){
//     int mid = (upper-lower+1)/2+lower;
//
//     bool work = true;
//     for (int i=0;i<b;i++){
//       while (hap<mid && pos2<a){
//         hap += pos[pos2];
//         pos2++;
//       }
//       if (hap<mid){
//         work = false;
//       }
//       hap/=2;
//     }
//     if (work){
//       lower = mid+1;
//     }else{
//       upper = mid;
//     }
//   }
//   cout << lower << endl;
//
  // hap = 0;
  // pos2 = 0;
  //
  // for (int i=0;i<b;i++){
  //   while(hap<lower){
  //     hap +=pos[pos2];
  //     tracklist[pos2] = i;
  //     pos2++;
  //   }
  //   hap/=2;
  // }
  // for (int i=0;i<b;i++){
  //   cout << tracklist[i] << endl;
  // }
// }
