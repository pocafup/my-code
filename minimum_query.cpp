#include <iostream>
#include <algorithm>

using namespace std;
inline int read() {
      int  x=0,w=1;
      char ch;
      while(ch<'0'||ch>'9')
      {
          if(ch=='-')
              w=-1;
          ch=getchar();
     }
     while(ch>='0'&&ch<='9')
         x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
     return x*w;
 }
int tree[100001];
int pos[100001];
void minimum(int si,int left, int right){
  if (right==left+1){
    tree[si] = max(pos[right],pos[left]);
    return;
  }
  int mid = (left+right)/2;
  minimum(si*2+1,left,mid);
  minimum(si*2+2,mid,right);
  tree[si] = max(tree[si*2+1],tree[si*2+2]);
}
int main(){
  int a,b; a = read();b = read();
  for (int i=0;i<a;i++) pos[i] = read();
  for (int i=0;i<b;i++){
    int c,d; cin >> c >> d;
    c--;d--;
    // memset(tree,0,sizeof(tree));
    minimum(0,c,d);
    cout << tree[0] << endl;
  }
}
