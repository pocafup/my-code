#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define root 0
#define N 10100
#define LN 14

vector <int> adj[N], costs[N], indexx[N];
int baseArray[N], ptr;
int chainNo, chainInd[N], chainHead[N], posInBase[N];
int depth[N], pa[LN][N], otherEnd[N], subsize[N];
int st[N*6], qt[N*6];

/*
 * make_tree:
 * Used to construct the segment tree. It uses the baseArray for construction
 */
void make_tree(int cur, int s, int e) {
	if(s == e-1) {
		st[cur] = baseArray[s];
		return;
	}
	int c1 = (cur<<1), c2 = c1+1, m = (s+e)>>1;
	make_tree(c1, s, m);
	make_tree(c2, m, e);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
}

/*
 * update_tree:
 * Point update. Update a single element of the segment tree.
 */
void update_tree(int cur, int s, int e, int x, int val) {
	if(s > x || e <= x) return;
	if(s == x && s == e-1) {
		st[cur] = val;
		return;
	}
	int c1 = (cur<<1), c2 = c1+1, m = (s+e)>>1;
	update_tree(c1, s, m, x, val);
	update_tree(c2, m, e, x, val);
	st[cur] = st[c1] > st[c2] ? st[c1] : st[c2];
}

/*
 * query_tree:
 * Given S and E, it will return the maximum value in the range [S,E)
 */
void query_tree(int cur, int s, int e, int S, int E) {
	if(s >= E || e <= S) {
		qt[cur] = -1;
		return;
	}
	if(s >= S && e <= E) {
		qt[cur] = st[cur];
		return;
	}
	int c1 = (cur<<1), c2 = c1 + 1, m = (s+e)>>1;
	query_tree(c1, s, m, S, E);
	query_tree(c2, m, e, S, E);
	qt[cur] = qt[c1] > qt[c2] ? qt[c1] : qt[c2];
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

int query_up(int u, int v) {
	if(u == v) return 0; // Trivial
	int uchain, vchain = chainInd[v], ans = -1;
	// uchain and vchain are chain numbers of u and v
	while(1) {
		uchain = chainInd[u];
		// cout << "fir && sec " << u << " " << v << endl;
		// cout << "qu       " << uchain << " " << vchain << endl;
		if(uchain == vchain) {
			// Both u and v are in the same chain, so we need to query from u to v, update answer and break.
			// We break because we came from u up till v, we are done
			if(u==v) break;
			// cout << "u      v " << posInBase[v]+1<< " " << posInBase[u]+1 << endl;
			query_tree(1, 0, ptr, posInBase[v]+1, posInBase[u]+1);
			// Above is call to segment tree query function
			// cout << "qt2 " << qt[1] << endl;
			if(qt[1] > ans) ans = qt[1]; // Update answer
			break;
		}
		query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u]+1);
		// Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
		// start till head. We then update the answer
		// cout << "test " << posInBase[chainHead[uchain]] << " " << posInBase[u]+1 << endl;
		// cout << "qt " << qt[1] << endl;
		if(qt[1] > ans) ans = qt[1];
		u = chainHead[uchain]; // move u to u's chainHead
		u = pa[0][u]; //Then move to its parent, that means we changed chains
	}
	return ans;
}

/*
 * LCA:
 * Takes two nodes u, v and returns Lowest Common Ancestor of u, v
 */
int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}

void query(int u, int v) {
	/*
	 * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
	 */
	int lca = LCA(u, v);
	// cout << u << " " << lca <<" " <<  v << endl;
	int ans = query_up(u, lca); // One part of path
	int temp = query_up(v, lca); // another part of path
	// cout << ans << " " << temp << endl;
	if(temp > ans) ans = temp; // take the maximum of both paths
	printf("%d\n", ans);
}

/*
 * change:
 * We just need to find its position in segment tree and update it
 */
void change(int i, int val) {
	int u = otherEnd[i];
	update_tree(1, 0, ptr, posInBase[u], val);
}

/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */
void HLD(int curNode, int cost, int prev) {
	if(chainHead[chainNo] == -1) {
		chainHead[chainNo] = curNode; // Assign chain head
	}
	chainInd[curNode] = chainNo;
	posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
	baseArray[ptr++] = cost;
	// cout << baseArray[ptr] << "  " << cost << endl;
	int sc = -1, ncost;
	// Loop to find special child
	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
			sc = adj[curNode][i];
			ncost = costs[curNode][i];
		}
	}
	// cout << "sc " <<  sc << " " << ncost <<  endl;
	if(sc != -1) {
		// Expand the chain
		HLD(sc, ncost, curNode);
	}

	for(int i=0; i<adj[curNode].size(); i++) if(adj[curNode][i] != prev) {
		if(sc != adj[curNode][i]) {
			// New chains at each normal node
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
}

/*
 *  used to set parent of a node, depth of a node, subtree size of a node
 */
void dfs(int cur, int prev, int _depth=0) {
	// cout << "dfs " << cur << endl;

	pa[0][cur] = prev;
	depth[cur] = _depth;
	subsize[cur] = 1;
	for(int i=0; i<adj[cur].size(); i++)
		if(adj[cur][i] != prev) {
			otherEnd[indexx[cur][i]] = adj[cur][i];
			dfs(adj[cur][i], cur, _depth+1);
			subsize[cur] += subsize[adj[cur][i]];
		}
}

int main() {
	ifstream cin ("desktop/abcdd.in");
	// auto start = high_resolution_clock::now();

	int t;cin >> t;
	while(t--) {
		ptr = 0;
		int n;
		cin >> n;
		// Cleaning step, new test case
		for(int i=0; i<n; i++) {
			adj[i].clear();
			costs[i].clear();
			indexx[i].clear();
			chainHead[i] = -1;
			for(int j=0; j<LN; j++) pa[j][i] = -1;
		}
		for(int i=1; i<n; i++) {
			int u, v, c;
			cin >> u >> v >> c;
			u--; v--;

			adj[u].push_back(v);
			costs[u].push_back(c);
			indexx[u].push_back(i-1);
			adj[v].push_back(u);
			costs[v].push_back(c);
			indexx[v].push_back(i-1);
		}

		chainNo = 0;
		// for (int i=0;i<n;i++){
		// 	for (int j=0;j<LN;j++){
		// 		cout << pa[j][i] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		dfs(root, -1); // We set up subsize, depth and parent for each node
		// cout << "level " << depth[0] << " " << depth[1] << " " << depth[2] << endl;
		HLD(root, -1, -1); // We decomposed the tree and created baseArray

		// for (int i=0;i<n;i++){
		// 	for (int j=0;j<LN;j++){
		// 		cout << pa[j][i] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;
		// cout << "size ";
		// for (int i=0;i<n;i++) cout << subsize[i] << " ";
		// cout << endl;
		// cout << "chain " << chainNo << endl;
		//for (int i=0;i<=n;i++) cout << depth[i] << " ";
		// cout << endl;
		// for (int i=0;i<chainNo+1;i++) cout << chainInd[i] << "     afsdnifasi   " << posInBase[i] << endl;
		make_tree(1, 0, ptr); // We use baseArray and construct the needed segment tree
		// for (int i=1;i<=ptr;i++) cout << baseArray[i] << " ";
		// for (int i=0;i<ptr;i++) cout << chainHead[i] << " ";
		// cout << endl;
		// for (int i=0;i<ptr*2;i++) cout << st[i] << " ";
		// cout << endl;
		// Below Dynamic programming code is for LCA.
		for(int i=1; i<LN; i++)
			for(int j=0; j<n; j++)
				if(pa[i-1][j] != -1)
					pa[i][j] = pa[i-1][pa[i-1][j]];

		// for (int i=0;i<n;i++){
    //   for (int j=0;j<LN;j++){
    //     cout << pa[j][i] << " ";
    //   }
    //   cout << endl;
    // }
		// cout << "qr " << endl;
		// cout << "lca " << LCA(0,1) << " " << LCA(0,2) << " " << LCA(1,2) << endl;
		// for (int i=0;i<n;i++){
		// 	if (i==21 || i == 33) {cout << endl << "LCA " << i << " = " << endl; cout << "level = " << depth[i] << endl;}
		//
		// 	for (int j=0;j<n;j++){
		// 		if (i==21 || i == 33)cout << LCA(i,j) << " ";
		// 	}
		// }
		// query(0,1);
		while(1) {
			char s[100];
			cin >> s;
			if(s[3]=='E') {
				break;
			}
			int a, b;
			cin >> a >> b;
			if(s[0]=='Q') {
				query(a-1, b-1);
			} else {
				change(a-1, b);
				// for (int i=0;i<ptr*2;i++) cout << st[i] << " ";
				// cout << endl;
			}
		}
	}
	// auto stop = high_resolution_clock::now();
  // auto duration = duration_cast<microseconds>(stop - start);
  // cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}
