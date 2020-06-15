#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define FORR(i,a,n) for(int i=a; i<n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<string> VS;
typedef pair<int,int> PI;
typedef pair<ll,ll> PL;
 
//int in() { int x; scanf("%d", &x); return x; }
//ll lin() { ll x; scanf("%lld", &x); return x; }
//void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

const ll MAX = 1e18;

int main(void){
    std::ios_base::sync_with_stdio(false);

    ll a,c;
    float b;
    cin >> a >> b;

    // b is a number with two digits after the decimal point 
    // so first convert into integer and multiple then divide 100
    // 1.1899*100 => 118.99 and 1.1999 to differentiate this two added 0.5
    c = b*100 + 0.5;
    cout << a*c/100;

    return 0;
}


/*

https://atcoder.jp/contests/abc169/tasks/abc169_c

input:
1000000000000000 9.99


output:
9990000000000000

*/
