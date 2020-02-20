#include <iostream>
#include <algorithm>
using namespace std;

long long MAXN = 500000;
long long n,m,a,b,c,d,e,f,g,h,sum;
long long cow[MAXN*3];
struct Cow {
    int w,u;
    bool operator<(const Cow& c) const {
    return u>c.u || (u==c.u && w>c.w);
    }
}

long long power(long long x,long long y,long long z) {
    long long p=1;
    for (int i = 1; i <= y; i++)
        p = (p*x) % z;
    return p;
}
int main() {

    cin >> n >> a >> b >> c >> d >> e >> f >> g >> h >> m;
    for (int i = 0; i<3*n; i++) {
        cow[i].w = (a*power(i,5,d) + b*power(i,2,d) + c) % d;
        cow[i].u = (e*power(i,5,h) + f*power(i,3,h) + g) % h;
    }

    sort (cow, cow+3*n);
    for (int i = 0; i < n; i++)
        sum += cow[i].w;

    cout << sum%m ;
}
