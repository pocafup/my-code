int LCA(int u , int v){
    if(level[u] < level[v]){
        swap(u,v) ;
    }
    int dist = level[u] - level[v] ;
    while(dist > 0){
        int raise_by = log2(dist);
        u = P[u][raise_by];
        dist -= (1<<raise_by) ;
    }

    if(u == v){
        return u ;
    }


    for(int j = MAXLOG ; j >= 0 ; --j){

        if((P[u][j] != -1) and (P[u][j] != P[v][j])){
            u = P[u][j] ;
            v = P[v][j] ;
        }
    }
    return parent[u] ;
}
void preprocess(){
    for(int i = 1 ; i <= N ; ++i){
        for(int j = 0 ; (1<<j) < N ; ++i){
            P[i][j] = -1;
        }
    }

    for(int i = 1 ; i <= N ; ++i){
        P[i][0] = parent[i] ;
    }

    for(int j = 1; (1<<j) < N ; ++j){
        for(int i = 1 ; i <= N ; ++i){
            if(P[i][j-1] != -1){
                P[i][j] = P[P[i][j-1]][j-1] ;
            }
        }
    }
}
