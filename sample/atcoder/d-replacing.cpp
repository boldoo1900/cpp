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

const int MAX = 1e5+5;

int main(void){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    VI vl(MAX);
    ll total = 0;
    FOR(i, n){
        int a;
        cin >> a;
        vl[a]++;            // count elements

        total += a;         // sum of all elements
    }

    int q;
    cin >> q;
    FOR(i, q){
        int b,c;
        cin >> b >> c;

        total += (c - b)*vl[b];     // diff amount of changed element
        vl[c] += vl[b];             // add number of elements to new one
        vl[b] = 0;                  // set to 0 previous one

        cout << total << endl;
    }

    return 0;
}


/*
https://atcoder.jp/contests/abc171/tasks/abc171_d?lang=ja

input:
4
1 2 3 4
3
1 2
3 4
2 4

output:
11
12
16


*/

