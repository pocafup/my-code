#include <algorithm>
#include <bitset>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MAXN 20
#define MAX_BITMASK (1 << n)
#define INF (1 << 30)

struct edge{
	int node;
	int dist;
};

int n, m;

vector<edge> adj[MAXN];
int dp[(1 << 20)][MAXN];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int a = 0, b = 0, d = 0;
		cin >> a >> b >> d;
		a--; b--;

		adj[a].push_back(edge{b, d});
		adj[b].push_back(edge{a, d});
	}

	for(int mask = 0; mask < MAX_BITMASK; mask++){
		for(int v = 0; v < MAXN; v++){
			dp[mask][v] = INF;
		}
	}

	for(int v = 0; v < n; v++){
		dp[0][v] = 0;
		dp[1 << v][v] = 0;
	}

	for(int mask = 0; mask < (1 << n); mask++){
		for (int u = 0; u < n; u++) {
			//We can't leave a node if we've never been there
			if((mask & (1 << u)) == 0)
				continue;

			for(edge& e: adj[u]){
				//Find the next node to visit
				int v = e.node;

				//We're not allowed to revisit a node
				if((1 << v) & mask)
					continue;

				int new_mask = mask | (1 << v);

				dp[new_mask][v] = min(dp[new_mask][v], dp[mask][u] + e.dist);
			}
		}
	}

	int ret = INF;

	for(int v = 0; v < n; v++){
		ret = min(ret, dp[MAX_BITMASK - 1][v]);
	}

	cout << ret << endl;
}
