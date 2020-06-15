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

    int n;
    cin >> n;

    ll ans = 1;
    bool ng = false;
    FOR(i, n){
    	ll tmp;
    	cin >> tmp;

    	if(tmp == 0){
    		cout << 0 << endl;
    		return 0;
    	}

    	// in order to avoid overflow ng 
    	// MAX/ans < tmp & ans*tmp > MAX little bit different
    	// MAX/ans < tmp 
    	// tmp*ans > MAX	overflow case exists
    	if(ng || MAX/ans < tmp){
    		ng = true;
    	}

    	ans *= tmp;    	
    }

    if(ng) 
    	cout << -1 << endl;
	else
    	cout << ans;

    return 0;
}


/*

https://atcoder.jp/contests/abc169/tasks/abc169_b

input:
3
101 9901 999999000001


output:
-1


*/
