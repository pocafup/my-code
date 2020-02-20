#include <iostream>
using namespace std;

int main(){
    int circle[10000] = { };
    int N,L;
    cin>>N,L;
    int pattern[100000];
    for(int i=0;i<L;++i){
        cin>>pattern[i];
    }
    int i=0,j=0;
    int length = L;
    while(N>1){
        i = (pattern[j]-1)%length;
        for(int k = i;k<N-2;k++){
            circle[k] = circle[k+1];
        }
        j = (j+1)%L;
        N--;
        length--;
    }
    cout<<circle[0];

}
