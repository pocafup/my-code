#include <iostream>
#include <string>

using namespace std;

int n,k;
string num;
int real=0;

int cut_Zero(){
    for(int i=k; i>=0; i--){
        if(num[i]=='0' && i!=n-1){
            int tmp=i;
            real++;
            for(int j=i-1; j>=0; j--){
                if(num[j]=='0'){
                    tmp--;
                    real++;
                }
            }
            for(int j=i-1; j<n; j++){
                num[j-i]=num[j+1];
            }
            return tmp;
        }
    }
    return 0;
}

void cut(int haveC){
    if(haveC==k){
        return;
    }
    for(int i=1; i<n-haveC-real; i++){
        if(num[i-1]>num[i]){
            for(int j=i-1; j<n-haveC-real; j++){
                num[j]=num[j+1];
            }
            cut(haveC+1);
            return;
        }
    }
    int maxN;
    char max='0';
    for(int i=0; i<n-haveC-real; i++){
        if(num[i]>max){
            max=num[i];
            maxN=i;
        }
    }
    for(int i=maxN; i<n-haveC-real; i++){
        num[i]=num[i+1];
    }
    cut(haveC+1);
    return;
}

int main(){
    getline(cin,num);
    //cin.ignore();
    n=num.length();
    cin>>k;
    int temp=cut_Zero();
    cut(temp);
    for(int i=0; i<n-real-k; i++){
        cout<<num[i];
    }
    return 0;
}
