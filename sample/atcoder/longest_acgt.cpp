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
 
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){

    string s;
    cin >> s;
    int n = s.size();
 
    int ans = 0;
    int len = 0;
    for(int i=0; i<n; ++i){
        if(string("ACGT").find(s[i]) == string::npos){
            len = 0;
        }
        else{
            ++ len;
            ans = max(ans, len);
        }
    }
    cout << ans << endl;
    return 0;

}
