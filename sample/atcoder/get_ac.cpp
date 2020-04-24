#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define FORR(i,a,n) for(int i=a; i<n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
 
int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){

    int n,q;
    string s;

    cin >> n >> q >> s;
    
    int count[n] = {0};
    FOR(i, n-1){
        count[i+1] = count[i] + (s.substr(i, 2) == "AC");
    }

    int v1,v2;
    FOR(i, q){
        cin >> v1 >> v2;
        cout << count[v2 -1] - count[v1-1] << endl;
    }

    return 0;
}
