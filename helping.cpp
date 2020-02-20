#include<iostream>
#include<cstdio>
using namespace std;

int n,m,a[100000];
int sum;

bool Check(int x){
    int j=0,cnt=1;

    for(int i=1;i<=n;i++){
        if(j+a[i]<=x)j+=a[i];
        else {
            j=a[i];
            cnt++;
        }
        if(cnt>m)return false;
    }
    return true;
}

int BinarySearch(int l,int r){
    while(l<=r){
        int mid=(l+r)>>1;
        if(Check(mid))r=mid-1;
        else l=mid+1;
    }
    return l;
}

int main(){
//  freopen("testdata.in","r",stdin);
//  freopen("testdata.out","w",stdout);
    int maxi = 0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxi = max(maxi,a[i]);
        sum+=a[i];
    }
    printf("%d\n",BinarySearch(maxi,sum));
    return 0;
}
