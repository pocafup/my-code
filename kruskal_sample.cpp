#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
const int MAX = 10005;
int id[MAX], nodes, b;
pair <long long, pair<pair<int, int>,pair<int,int> > > p[1005][1005];
pair<int,int> pos[1005];
void initialize()
{
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int find(int x)
{
    // while(id[x] != x)
    // {
    //     id[x] = id[id[x]];
    //     x = id[x];
    // }
    return id[x] == x ? x : id[x] = find(id[x]);
}

void union1(int x, int y)
{
    int p = find(x);
    int q = find(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<pair<int,int>,pair<int, int> > > p[][])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < b;i++)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}

long long dis(pair<long long,long long> aa, pair<long long,long long> bb){
  return (aa.first-bb.first)*(aa.first-bb.first)+(aa.second-bb.second)*(aa.second-bb.second);
}
int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> b;
    for(int i = 0;i < b;i++)
    {
        cin >> pos[i].first >> pos[i].second;
    }
    // Sort the edges in the ascending order
    for (int i=0;i<b;i++){
      for (int j=0;j<b;j++){
        if (i!=j){
          dist = dis(pos[i],pos[j]);
          p[i][j] = make_pair(dist,make_pair(pos[i],pos[j]));
        }
      }
    }
    sort(p,p+b);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}
