#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;

#define NMAX 100000
#define KMAX 20

int moves[NMAX];

int dp[NMAX + 1][KMAX + 1][3];

int main() {
    int n, k;
    cin >> n >> k;

    char s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (s == 'H') moves[i] = 0;
        if (s == 'P') moves[i] = 1;
        if (s == 'S') moves[i] = 2;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int state = 0; state < 3; state++) {
                if (i == 0) {
                    dp[i][j][state] = 0;
                } else {
                    if (j == 0) {
                        dp[i][j][state] = dp[i-1][j][state] + (moves[i-1] == state ? 1 : 0);
                    } else {
                        int ostate1 = (state + 1) % 3;
                        int ostate2 = (state + 2) % 3;
                        dp[i][j][state] = max(max(dp[i-1][j][state], dp[i-1][j-1][ostate1]), dp[i-1][j-1][ostate2]) + (moves[i-1] == state ? 1 : 0);
                    }
                }
            }
        }
    }

    printf("%d\n", max(max(dp[n][k][0], dp[n][k][1]), dp[n][k][2]));
}
