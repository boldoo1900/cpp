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
typedef vector<string> VS;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
 
int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){

	int ans = 0;
    int last = 0;
    for(int i = 0; i < 5; i++){
        int x;
        cin >> x;
        ans += (x + 9) / 10 * 10;
        if(x % 10 == 0){
            continue;
        }
        last = max(last, 10 - x % 10);
    }
    cout << ans - last << endl;

    return 0;
}

//https://atcoder.jp/contests/abc123/tasks/abc123_b
// shiidel: svvld nemeh hamgiin bolomjit toog ni olno busad ni bvgd 
// adilhan 0 eer togsoh uchir nemeh daraalal hamaagui

// input: 
// 29
// 20
// 7
// 35
// 120
//output:
//215
