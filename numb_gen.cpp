#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int main (){
  srand(time(NULL));
  int a,b; cin >> a >> b;
  pair<int,int> N[a], M[b];
  for (int i=0;i<a;i++){
    N[i].first = rand() % 100 + 1;
    N[i].second = rand() % 100 + 1;
    while(N[i].first == N[i].second){
      N[i].first = rand() % 100+1;
    }
    cout << N[i].first << " " << N[i].second << endl;
  }
  for (int i=0;i<b;i++){
    M[i].first = rand() % a+1;
    M[i].second = rand() % a+1;
    while(M[i].first == M[i].second){
      M[i].first = rand() % a+1;
    }
    cout << M[i].first << " " << M[i].second << endl;
  }


}
