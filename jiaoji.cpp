#include <iostream>
#include <string>
using namespace std;
int main(){
    bool ccc=true;
    string a,b;
    cin>>a>>b;
    if(a.length()==b.length()){
        for(int i=0;i<a.length();i++){
            if(abs(a[i]-b[i]) == 'a'-'A'){
                ccc = true;
            }else if(int(a[i])!=int(b[i])){
                cout << int(a[i]) << int(b[i]) << endl;
                ccc = false;
            }

        }
    }
    if(ccc == true){
        cout<<"same";
    }else{
        cout<<"not same";
    }

}
