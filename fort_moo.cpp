#include <iostream>
#include <algorithm>

using namespace std;

int grid[201][201];
pair<int,int> vertical[201][201];
pair<int,int> horizontal[201][201];
int main(){
  int a,b; cin >> a >> b;
  int fir = 1, sec = 1;
  int q1 = 0, q2=0;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      char c; cin >> c;
      if(c=='.') grid[i][j] = 0;
      else grid[i][j] = 1;
    }
  }
  for (int i=0;i<a;i++){
    q1=0;
    for (int j=0;j<b;j++){

      if (grid[i][j] == 0){
        vertical[i][j] = make_pair(fir,q1); fir++;

      }else {q1++;vertical[i][j] = make_pair(0,q1);}
    }
  }
  for (int i=0;i<b;i++){
    q2 = 0;
    for (int j=0;j<a;j++){
      if (grid[j][i] ==0){
        horizontal[j][i] = make_pair(sec,q2);
        sec++;
      }else{q2++; horizontal[j][i] = make_pair(0,q2);}
    }
  }
  int maxi = 0;
  for (int i=0;i<b;i++){
    for (int j=0;j<a;j++){
      for (int k=b-1;k>=i+1;k--){
        for (int l=a-1;l>=j+1;l--){
          bool n = false;
          pair<int,int> kj = vertical[j][k];
          pair<int,int> ij = vertical[j][i];
          pair<int,int> kl = vertical[l][k];
          pair<int,int> il = vertical[l][i];
          pair<int,int> hil = horizontal[l][i];
          pair<int,int> hij = horizontal[j][i];
          pair<int,int> hkl = horizontal[l][k];
          pair<int,int> hkj = horizontal[j][k];
          int temp1 = kj.first-ij.first;
          int temp2 = kl.first-il.first;
          int temp3 = hil.first-hij.first;
          int temp4 = hkl.first-hkj.first;
          if (temp1 == temp2  && temp3 == temp4 && temp1>0 && temp2>0 && temp3>0&&temp4>0 &&
              kj.second == ij.second && kl.second == il.second && hil.second == hij.second && hkl.second == hkj.second &&
              grid[i][j] !=1 && grid[i][l]!=1 && grid[k][j]!=1 && grid[k][l]!=1){
                n = true;

              }

          if (n) {maxi = max((k-i+1)*(l-j+1),maxi);break;}
        }
      }
    }
  }
  //cout << horizontal[0][0].second << " " << horizontal[3][0].second << endl;
  cout << maxi;
}





// #include <iostream>
// #include <algorithm>
//
// using namespace std;
//
// int grid[201][201];
// pair<int,int> vertical[201][201];
// pair<int,int> horizontal[201][201];
// int main(){
//   int a,b; cin >> a >> b;
//   int fir = 1, sec = 1;
//   int q1 = 0, q2=0;
//   for (int i=0;i<a;i++){
//     for (int j=0;j<b;j++){
//       char c; cin >> c;
//       if(c=='.') grid[i][j] = 0;
//       else grid[i][j] = 1;
//     }
//   }
//   for (int i=0;i<a;i++){
//     q1=0;
//     for (int j=0;j<b;j++){
//
//       if (grid[i][j] == 0){
//         vertical[i][j] = make_pair(fir,q1); fir++;
//
//       }else {q1++;vertical[i][j] = make_pair(0,q1);}
//     }
//   }
//   // for (int i=0;i<a;i++){
//   //   for (int j=0;j<b;j++){
//   //     cout << vertical[i][j].first << " ";
//   //   }
//   //   cout << endl;
//   // }
//   // cout << endl;
//   // for (int i=0;i<a;i++){
//   //   for (int j=0;j<b;j++){
//   //     cout << vertical[i][j].second << " ";
//   //   }
//   //   cout << endl;
//   // }
//   for (int i=0;i<b;i++){
//     q2 = 0;
//     for (int j=0;j<a;j++){
//       if (grid[j][i] ==0){
//         horizontal[j][i] = make_pair(sec,q2);
//         sec++;
//       }else{q2++; horizontal[j][i] = make_pair(0,q2);}
//     }
//   }
//   // for (int i=0;i<a;i++){
//   //   for (int j=0;j<b;j++){
//   //     cout << horizontal[i][j].first << " ";
//   //   }
//   //   cout << endl;
//   // }
//   // for (int i=0;i<a;i++){
//   //   for (int j=0;j<b;j++){
//   //     cout << horizontal[i][j].second << " ";
//   //   }
//   //   cout << endl;
//   // }
//   int maxi = 0;
//   for (int i=0;i<a;i++){
//     for (int j=0;j<b;j++){
//       for (int k=i+1;k<a;k++){
//         for (int l=j+1;l<b;l++){
//           bool n = false;
//           pair<int,int> kj = vertical[j][k];
//           pair<int,int> ij = vertical[j][i];
//           pair<int,int> kl = vertical[l][k];
//           pair<int,int> il = vertical[l][i];
//           pair<int,int> hil = horizontal[l][i];
//           pair<int,int> hij = horizontal[j][i];
//           pair<int,int> hkl = horizontal[l][k];
//           pair<int,int> hkj = horizontal[j][k];
//           int temp1 = kj.first-ij.first;
//           int temp2 = kl.first-il.first;
//           int temp3 = hil.first-hij.first;
//           int temp4 = hkl.first-hkj.first;
//           if (temp1 == temp2  && temp3 == temp4 && temp1>0 && temp2>0 && temp3>0&&temp4>0 &&
//               kj.second == ij.second && kl.second == il.second && hil.second == hij.second && hkl.second == hkj.second){
//                 n = true;
//                 //cout << "        " <<  kj.second << " " << ij.second << " " << kl.second << " " << il.second << " " << hil.second << " " << hij.second << " " <<  hkl.second  << " " << hkj.second << endl;
//               }
//           // if (n && (k-i+1)*(l-j+1)>maxi) {
//           //   cout << temp1 << " "<< temp2 << " " << temp3 << " " << temp4 << endl;
//           //   cout << i << " " << j <<  " " << k << " " << l << endl;
//           // }
//           if (n) maxi = max((k-i+1)*(l-j+1),maxi);
//         }
//       }
//     }
//   }
//   //cout << horizontal[0][0].second << " " << horizontal[3][0].second << endl;
//   cout << maxi;
// }
