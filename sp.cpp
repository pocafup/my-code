#include <iostream>
#include <algorithm>
using namespace std;


char sector[1000][1000];      /* extras form border of \0's */
int checked[1000][1000];      /* marks those squares we have checked */

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int nmeteors;

int removeneighbors (i, j) {
    int k, i1, j1;
    checked[i][j] = nmeteors;
    sector[i][j] = '!';         /* seen this one! */
    for (k = 0; k < 4; k++) {
        i1 = i + dx[k];
        j1 = j + dy[k];
        if (checked[i1][j1] || sector[i1][j1] != '*') continue;
        removeneighbors (i1, j1);
    }
}

int main() {
    int i, j, n;
    cin = fopen ("space.in", "r");
    cout = fopen ("space.out", "w");
    cscanf (cin, "%d", &n);
    for (i = 1; i <= n; i++)
        cscanf (cin, "%s", &sector[i][1]);

        /* count the meteors */
    nmeteors = 0;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n;  j++) {
            if (sector[i][j] != '*') continue;
            nmeteors++;
            removeneighbors(i, j);
        }
    }
    cprintf (cout, "%d\n", nmeteors);
    exit (0);
}
