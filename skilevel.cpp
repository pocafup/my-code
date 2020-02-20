#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
int grid[501][501];
int start[501][501];
int vis[501][501];
int size[501][501];
int x[2] = {0,1};
int dist,ans;
int a,b,c;
int y[2] = {1,0};
struct node{
  int x,y;
};

node getnode(int zx,int zy){
  node no;
  no.x = zx;
  no.y = zy;
  return no;
}

vector<node> child[501][501];
bool sorted(pair<int,pair<node,node> > aa, pair<int,pair<node,node> > bb){
  return aa.first<bb.first;
}
vector<pair<int,pair<node,node> > > rd;
void update_child(vector<node> aa, int num){

  for (int i=0;i<aa.size();i++){

    vector<node> chi = child[aa[i].x][aa[i].y];
    if (vis[aa[i].x][aa[i].y]) continue;
    vis[aa[i].x][aa[i].y] = true;
    size[aa[i].x][aa[i].y] = num;
    if(size[aa[i].x][aa[i].y]>=c && start[aa[i].x][aa[i].y]==1){
      ans+=dist;
      start[aa[i].x][aa[i].y] = 0;
    }
    update_child(chi,num);
    // for (int j=0;j<child[chi[i].x][chi[i].y].size();j++){
    //   if (vis[child[chi[i].x][chi[i].y][j].x][child[chi[i].x][chi[i].y][j].y]) continue;
    //   // vis[child[chi[i].x][chi[i].y][j].x][child[chi[i].x][chi[i].y][j].y] = true;
    //   update_child(child[child[chi[i].x][chi[i].y][j].x][child[chi[i].x][chi[i].y][j].y],num);
    // }
  }
}
node pa[501][501];
bool is_equal(node aa, node bb){
  // cout << (aa[i].x==bb.x && aa[i].y==bb.y) << "     f " << endl;
  return (aa.x==bb.x && aa.y==bb.y);
}
node find_parent(node index){
  // cout << pa[index.x][index.y].x <<" " << pa[index.x][index.y].y << " " <<index.x << " " << index.y << endl;
  if (!is_equal(pa[index.x][index.y],index)) return find_parent(pa[index.x][index.y]);
  return index;
}
bool Is_union(node index1, node index2){
  return (size[index1.x][index1.y]==size[index2.x][index2.y] && size[index1.x][index1.y]!=1);
}
void make_union(node index1, node index2){
  // pa[index1.x][index1.y] = index2;
  // pa[index2.x][index2.y] = index1;
  child[index2.x][index2.y].push_back(index1);
  child[index1.x][index1.y].push_back(index2);
}

int main(){
  cin >> a >> b >> c;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> grid[i][j];
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      pa[i][j] = getnode(i,j);
    }
  }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      for (int k=0;k<2;k++){
        if (i+x[k]<a && j+y[k]<b){
          rd.push_back(make_pair(abs(grid[i][j]-grid[i+x[k]][j+y[k]]),make_pair(getnode(i,j),getnode(i+x[k],j+y[k]))));
          // cout << rd[rd.size()-1].first << endl;
        }
      }

    }
  }

  // cout << endl << endl;
  sort(rd.begin(),rd.end(),sorted);
  // for (int i=0;i<rd.size();i++){
  //   cout << rd[i].first << " " << rd[i].second.first.x << " " << rd[i].second.first.y << " " << rd[i].second.second.x << " " << rd[i].second.second.y << endl;
  // }
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      size[i][j] = 1;
    }
  }
  dist = 0;
  ans = 0;
  for (int i=0;i<a;i++){
    for (int j=0;j<b;j++){
      cin >> start[i][j];
    }
  }
  for (int i=0;i<rd.size();i++){
    // cout << rd[i].first << " " << rd[i].second.first.x << " " << rd[i].second.first.y << " " << rd[i].second.second.x << " " << rd[i].second.second.y << endl << endl;

    dist = rd[i].first;
    node n1 = rd[i].second.first;
    node n2 = rd[i].second.second;
    if (!Is_union(n1,n2)){
      make_union(n1,n2);
      int temp = size[n1.x][n1.y];
      size[n1.x][n1.y] += size[n2.x][n2.y];
      size[n2.x][n2.y]+= temp;
      memset(vis,0,sizeof(vis));
      vis[n1.x][n1.y] = true;
      vis[n2.x][n2.y] = true;
      update_child(child[n2.x][n2.y],size[n2.x][n2.y]);
      update_child(child[n1.x][n1.y],size[n2.x][n2.y]);
    }

    if(size[n1.x][n1.y]>=c && start[n1.x][n1.y] == 1){
      ans+=dist;
      start[n1.x][n1.y] = 0;
    }
    if(size[n2.x][n2.y]>=c && start[n2.x][n2.y] == 1){
      ans+=dist;
      start[n2.x][n2.y] = 0;
    }
  }
  //   cout << ans << endl;
  //
  //   for (int i=0;i<a;i++){
  //     for (int j=0;j<b;j++){
  //       cout << size[i][j] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }

  cout << ans << endl;
}
