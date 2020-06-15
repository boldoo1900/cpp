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


int main(void){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, n;
    cin >> x >> n;

    VI vec(102);
    FOR(i, n){
        int tmp;
        cin >> tmp;
        vec[tmp] = 1; 
    }

    PI ans(99999, -1);
    FOR(i, 102){
        if(vec[i] == 1) continue;

        int diff = abs(x-i);
        ans = min(ans, PI(diff, i));        // pair compare is checks first element, if element same then checks second
    }

    cout << ans.second << endl;
    return 0;
}


/*
https://atcoder.jp/contests/abc170/tasks/abc170_c
*/
