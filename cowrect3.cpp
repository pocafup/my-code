#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;
#define pp pair<int,int>
struct node{
  int x,y;
  char id;
}cow[100005];
int tot = 0, temp = 0;
int a,b,c; char d;
void add(int aa, int bb, char cc){
  cow[++tot].x = aa;
  cow[tot].y = bb;
  cow[tot].id = cc;
}
bool sorted(node aa, node bb){
  return aa.x<bb.x;
}
bool between(pp aa,int b){
  return aa.first>b && aa.second<b;
}//这个是表示一个数是否在两个数直接
bool posible = true;
pp find_pair(int aa, int bb){
  int mini = 1e8,maxi = 0;
  int low = aa, high = bb;
  while(cow[low-1].x==cow[aa].x) {low--;if (low==0)break;}
  while(cow[high-1].x==cow[bb].x) {high++; if (high == 0) break;}
  //这是一个很重要的判断：
  //因为我们在排序的时候有可能遇到x相等的点，这个点并不会被搜索，但是这个点仍然需要判断。在这个时候就需要往前和后搜索x相等的点
  for (int i=low;i<=high;i++){
    if (cow[i].id=='G'){
      if (cow[i].y>max(cow[aa].y,cow[bb].y)) mini = min(mini,cow[i].y);
      else if (cow[i].y<min(cow[aa].y,cow[bb].y)) maxi = max(maxi,cow[i].y);
      else posible = false;
    }
  }//如果这两个点中间有G就进行以下判断：
  //1.如果这个G的y坐标在这两个点的y之上，那么我们将最高值更新
  //2.如果这个G的坐标在y之下，我们将最小值之下，我们更新最小值
  //3.如果这个G在两个坐标中间，那么这两个点必然不可能选（因为无论怎么样连最后G都会在这个范围里）
  return make_pair(mini,maxi);
}
pp in_range(int aa, int bb, pp bo){
  int maxi = 0,mini = 1e8;
  for (int i=aa;i<=bb;i++){
    bool update = true;
    while(update){
      if (cow[i].id!='G'){
        if (between(bo,cow[i].y)){
          maxi = max(maxi,cow[i].y);
          mini = min(mini,cow[i].y);
          temp++;
        }
      }
    }
  }//现在已经找出了在这个点上面最低的G点和下面最高的G点
  //我们在这个范围里面搜索所以的H，更新最高点和最低点（前提是要在G点的范围内）
  return make_pair(maxi,mini);
}
int main(){
  ios::sync_with_stdio(0);
  cin >> a;
  for (int i=0;i<a;i++){
    cin >> b >> c >> d;
    add(b,c,d);
  }
  int ans = 0, breed = 1;
  sort(cow+1,cow+tot+1,sorted);
  //以上不解释
  for (int i=1;i<=a;i++){
    for (int j=i+breed;j<=a;j++){
      if (cow[i].id=='G'||cow[j].id == 'G') continue;//如果两个点中有G就不需要判断
      posible = true;
      temp = 0;
      pp bounds = find_pair(i,j);//先找G的范围
      if (!posible) continue;
      pp res = in_range(i,j,bounds);//再找H的范围
      if (temp){
        if(temp>breed){
          //如果H的数量大于之前的，直接更新
          breed = temp;
          ans = abs(res.first-res.second)*abs(cow[j].x-cow[i].x);
        }else if (temp==breed) ans = min(ans,abs(res.first-res.second)*abs(cow[j].x-cow[i].x));//否则更新面积（底『x的差』乘高『最高y值和最低y值的差』
      }
    }
  }
  cout << breed << endl << ans;
}
