#include <string>
#include <iostream>
#include <vector>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256
vector<char> vec;
int curr;
/* pat -> pattern
    txt -> text
    q -> A prime number
*/
void search(char pat[], char txt[], int q){

  int M = strlen(pat);
  int N = strlen(txt);
  int i, j;
  int p = 0;
  int t = 0;
  int h = 1;

  for (i = 0; i < M - 1; i++) h = (h * d) % q;
  for (i = 0; i < M; i++){
      p = (d * p + pat[i]) % q;
      t = (d * t + txt[i]) % q;
      cout << t << " " << p << endl;
  }
  cout << p << endl;
  for (i = 0; i <= N - M; i++){
    vec.push_back(txt[i]);
    if ( p == t ){
      for (j = 0; j < M; j++){
        if (txt[i+j] != pat[j]) break;
      }
      if (j == M) {
        vec.pop_back();
        cout << i << endl;
        i += M-1;
        t = curr;
      }
    }
    for (int i=0;i<vec.size();i++) cout << vec[i];
    cout << endl;
    cout << t << " " << p << endl;
    if (i < N-M){
      t = (d*(t - txt[i]*h) + txt[i+M])%q;
      if (t < 0) t += q;
      curr = t;
    }
  }
  for (int i=N-M+1;i<N;i++)vec.push_back(txt[i]);
}

int main(){

    char txt[] = "whatthemomooofun";

    char pat[] = "moo";
    int q = 1e6+7;
    search(pat, txt, q);

    for (int i=0;i<vec.size();i++) cout << vec[i];
}
