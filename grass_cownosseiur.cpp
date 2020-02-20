#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>

using namespace std;
pair<int,int> posi[100001];
vector<int> vec;
vector<int> pos[100001];
vector<int> pos2[100001];
vector<vector<int> > connect;
bool vis[100001];
stack<int> st;
void dfs(int aa){
    for (int i=0;i<pos[aa].size();i++){
        if (!vis[pos[aa][i]]){
            vis[pos[aa][i]] = true;
            st.push(pos[aa][i]);
            dfs(pos[aa][i]);
        }
    }
}
int dfs2(int aa,int start,int num){
    for (int i=0;i<pos2[aa].size();i++){
        if (!vis[pos2[aa][i]]){
            vis[pos2[aa][i]] = true;
            vec.push_back(pos2[aa][i]);
            num = dfs2(pos2[aa][i],start,num);
        }
    }
    if (aa == start) num++;
    return num;
}
void back_dfs(int start){
    for (int i=0;i<pos2[start].size();i++){
        if (vis[pos2[start][i]]){
            vis[pos2[start][i]] = false;
            back_dfs(pos2[start][i]);
        }
    }
}
int main(){

    int a,b; cin >> a >> b;
    for (int i=0;i<b;i++){
        cin >> posi[i].first >> posi[i].second;
        posi[i].first--; posi[i].second--;
        pos[posi[i].first].push_back(posi[i].second);
        pos2[posi[i].second].push_back(posi[i].first);
    }
    for (int i=0;i<a;i++){
        if (!vis[i]){
            vis[i] = true;
            st.push(i);
            dfs(i);
        }
    }
    memset(vis,0,sizeof(vis));
    while(!st.empty()){
        vector<int> temp;
        swap(temp,vec);
        if (!vis[st.top()]){
            vis[st.top()] = true;
            vec.push_back(st.top());
            cout << dfs2(st.top(),st.top(),0) << endl;
            if(dfs2(st.top(),st.top(),0)>1){

                connect.push_back(vec);
            }else{
                back_dfs(st.top());
            }
        }
        st.pop();
    }
    for (int i=0;i<connect.size();i++){
        for (int j=0;j<connect[i].size();j++){
            cout << connect[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
