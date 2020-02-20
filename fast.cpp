#include<iostream>
#include<algorithm>
using namespace std;

int a[100000005],con,m,n,b,mid;
void qsort(int l,int r)
{
    mid=(l+r)/2;
    m=l,n=r;

    while(m<=n){
        while(a[m]<a[mid]) m++;
        while(a[n]>a[mid]) n--;
        if(m<=n && a[m]>=a[n])
        {
            swap(a[m],a[n]);

        }
        m++;
        n--;

    }

    if(l<=n) qsort(l,n);
    if(m<=r) qsort(m,r);
}

int main()
{
    cin>>con;
    for(int i=1;i<=con;i++) cin>>a[i];
    qsort(1,con);
    for(int i=1;i<con;i++) cout<<a[i]<<" ";
    cout<<a[con];
    return 0;
}
