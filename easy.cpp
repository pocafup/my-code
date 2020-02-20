#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> st;
    int a;cin >> a;
    while(!cin.eof()){
        st.push(a);
        cin >> a;
    }
    st.pop();
    a+=30;
    int ans = 0;
    while(!st.empty()){
        if (st.top()<=a) ans++;
        st.pop();
    }
    cout << ans;

}
