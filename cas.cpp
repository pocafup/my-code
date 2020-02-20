#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    long long a,b,c; cin >> a >> b >> c;
    long long  q1[a], q2[a];
    for (int i=0;i<a;i++){
        cin >> q1[i] >> q2[i];
    }
    sort(q1,q1+a);
    sort(q2,q2+a);
    for (int i=0;i<a;i++){
        cout << q1[i] << " " << q2[i] << endl;
    }
    long long count = 0;
    for (int i=0;i<a;i++){
        if (q1[i]>q2[i]){
            count += (q1[i]-q2[i])*b;
        }else if (q1[i]<q2[i]){
            count += (q2[i]-q1[i])*c;
        }
        cout << count << endl;
    }
    cout << count;
}
