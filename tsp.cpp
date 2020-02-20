//
//  tsp.cpp
//  alphastar
//
//  Created by 许致远 on 2019/8/1.
//  Copyright © 2019年 许致远. All rights reserved.
//

#include "tsp.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int,int> > path[1001];
pair<int,vector<int> > dp[21][21];

int main(){
    int N,M; cin >> N >> M;
    for (int i=0;i<M;i++){
        int c,d,e; cin >> c >> d >> e;
        c--;d--;
        path[c].push_back(make_pair(d,e));
        path[d].push_back(make_pair(c,e));
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
                vector<int> vec;
                dp[i][j] = make_pair(2*1e8,vec);
            
            
        }
    }
    for (int i=0;i<N;i++){
        for (int j=0;j<path[i].size();j++){
            if (i!=j){
                vector<int> vec;
                vec.push_back(i);
                vec.push_back(path[i][j].first);
                dp[2][path[i][j].first] = make_pair(path[i][j].second,vec);
            }
        }
    }
    int ans = 1e8;
    for (int i=3;i<N;i++){
        for (int j=0;j<N;j++){
            vector<int> vec = dp[i-1][j].second;
            for (int k=0;k<path[j].size();k++){
//                bool n = false;
//                for (int l=0;l<vec.size();l++){
//                    if (vec[l]==path[j][k].first){
//                        n = true;
//                        break;
//                    }
//                }//check to eliminate duplicates
                vector<int>::iterator it;
                
                it = find(vec.begin(), vec.end(),path[j][k]);
                if(*it)continue;
                if(dp[i][j].first>dp[i-1][j].first+path[j][k].second){
                    vector<int> temp = vec;
                    temp.push_back(path[j][k].first);
                    dp[i][path[j][k].first] = make_pair(dp[i-1][j].first+path[j][k].second,temp);
                }
            }
            if (i==N-1) ans = min(ans,dp[i][j].first);
        }
    }
    cout << ans;
}
