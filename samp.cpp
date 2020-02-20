#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cassert>

using namespace std;

#define MAXN 100010

int PSUM[MAXN * 2];

int main() {

  int N; cin >> N;
  vector<pair<int, char> > A(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  //A.push_back(make_pair(1000000010, '?'));
  sort(A.begin(), A.end());

  int result = 0;
  for(int i = 0; i < N; ) {
    int sz = 1;
    while(i + sz < N && A[i].second == A[i + sz].second) {
      ++sz;
    }
    result = max(result, A[i + sz - 1].first - A[i].first);
    i += sz;
  }

  int psm = 0;
  memset(PSUM, 0x3F, sizeof(PSUM));
  for(int i = 0; i < N; i++) {
    PSUM[N + psm] = min(PSUM[N + psm], A[i].first);
    psm += A[i].second == 'G' ? 1 : -1;
    result = max(result, A[i].first - PSUM[N + psm]);
  }

  cout << result << endl;
  return 0;
}
