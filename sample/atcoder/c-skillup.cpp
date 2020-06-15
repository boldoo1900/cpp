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

const int m = 2019;

int main(void){
    std::ios_base::sync_with_stdio(false);

    int n,m,x;
    cin >> n >> m >> x;
    int a[12][12];
    VI  c(n);

    FOR(i, n){
        cin >> c[i];
        FOR(j, m){
            cin >> a[i][j];
        }
    }

    int ans = INF;
    FOR(s, 1<<n){           // left shift: (1<<n) == (2 raised power of n) == pow(2, n)
        int cost = 0;
        VI d(m);

        FOR(i, n){
            if (s>>i&1){    // right shift 
                cost += c[i];
                FOR(j, m){
                    d[j] += a[i][j];
                }
            }            
        }

        // if d[i] array elements is all higher than x, ans value replaced by min 
        if((lower_bound(ALL(d), x) - d.begin()) == 0)       
            ans = min(ans, cost);
    }
    cout << ans;

    return 0;
}




/*
https://atcoder.jp/contests/abc167/tasks/abc167_a?lang=ja

solution:
check all possible cases pow(2, n) then find min cost

input: 
3 3 10
60 2 2 4
70 8 7 9
50 2 3 9

output: 
120


*/

