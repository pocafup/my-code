void recur(int way, int left, int right, int low,int high){
    if (lazy[way] != 0) {
        N[way] += (right-left+1)*lazy[way];
        if (left != right){
            lazy[way*2]   += lazy[way];
            lazy[way*2+1]   += lazy[way];
        }
        lazy[way] = 0;
    }
    if (left>right || left>high || right<low)return ;
    if (left>=low && right<=high){
      N[way] += right-left+1;
      if (left != right){
          lazy[way*2]^=1;
          lazy[way*2+1]^=1;
      }
      return;
    }
    recur(way*2, left, (left+right)/2, low, high);
    recur(way*2+1, (left+right)/2+1, right, low, high);
    N[way] = N[way*2] + N[way*2+1];
}

int sum(int left, int right, int low, int high, int way) {
  if (lazy[way] != 0) {
    N[way] += (right-left+1)*lazy[way];
    if (left != right) {
        lazy[way*2+1] += lazy[way];
        lazy[way*2+2] += lazy[way];
    }
    lazy[way] = 0;
  }
  if (left>right || left>high || right<low) return 0;
  if (left>=low && right<=high) return N[way];

  return sum(left, (left + right)/2, low, high, 2*way+1) +
         sum((left + right)/2+1, right, low, high, 2*way+2);
}
void add(int k,int l,int r)//添加lazy标记
{
    if(lazy[k])//如果将要下传的点已经有了标记，就把他去掉然后再修改数据。因为一个点两次修改数据后数值还是和原来的一样。
    {
        lazy[k]=0;
    }else
    lazy[k]=1;
    s[k]=r-l+1-s[k];//剩下的灯光数,修改数据
    return ;
}
void Update(int l,int r,int way) {       //更新[l,r]区间内的状态
    if(l<=tree[way].l && tree[way].r<=r) {
        tree[way].v=tree[way].len()-tree[way].v;
        tree[way].lazy^=1;
        return;
    }
    Pushdown(way);
    int mid=tree[way].mid();
    if(l<=mid)  Update(l,r,lc);
    if(r>mid)   Update(l,r,rc);
    Pushup(way);
}
