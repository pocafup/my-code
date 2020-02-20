#include <iostream>
using namespace std;
int a[105];
int l;
int k;
bool b=false;
void ll(int L,int R,int m){
    if(m==0){
        b=true;
        return;
    }
    else if(k==a[m]){
     cout<<m;
    }
    else if(k<a[m]){
        ll(1,m-1,m/2);
    }
    else if(a[m]<k){
        ll(m+1,R,(m+1+R)/2);
    }
}
int main(){
    cin>>l;
    cin>>k;
    for(int i=1;i<=l;i++){
        cin>>a[i];
    }
    sort(a+1,a+l+1);
    ll(1,l,(l+1)/2);
    if(b==true){
        cout<<"NO RESULT";
    }
}
