#include <iostream>
using namespace std;
int main(){
    string s;
    int abc[3]={0};
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='='){
            if(s[i+1]>='0'&&s[i+1]<='9')
                abc[int(s[i-2]-97)]=int(s[i+1]-'0');
            else
                abc[int(s[i-2]-97)]=abc[int(s[i+1]-97)];
        }
    }
    cout<<abc[0]<<" "<<abc[1]<<" "<<abc[2];
    return 0;
}
