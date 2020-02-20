#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
long long tot=0,top=0;
long long a[10000000],b[10000000],c[10000000];
int main(){
    long long n,k;
    cin>>n>>k;
    for(long long i=1;i<=sqrt(n);i++){
        if(n%i==0){
            a[++tot]=i;
            if(i!=n/i && (n/i)%i==0) b[++top]=n/i;
        }
    }

    long h=top;
    for(long i=1;i<=top;i++)
    c[h--]=b[i];

    if(k>tot+top) {
        cout<<-1;
        return 0;
    }

    else cout<<a[k];
}
