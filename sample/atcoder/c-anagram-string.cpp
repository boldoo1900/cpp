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
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
 
//int in() { int x; scanf("%d", &x); return x; }
//ll lin() { ll x; scanf("%lld", &x); return x; }
//void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(){
	ios::sync_with_stdio(false);

    int n;
    cin >> n;
    unordered_map <string, int> mp;	 // map ni ooroo bagaasaa ehleed eremdlegdsen bdag ene tohioldold erembleh shaardlaga bhgui uchir hurdnii huvid hemnelttei

    FOR(i, n){
    	string s;
    	cin >> s;

    	sort(ALL(s));
    	mp[s]++;		// map d default value bhgui ved ter string key geer ni 0 gsen default utgatai vvsene
    }

    ll ans = 0;
    for(auto p:mp){
    	// 1 ees n hvrtelh pair vvdiin too ni "n/(n-1)/2" gsen dvremtei
    	ans += (ll) p.second*(p.second - 1)/2;
    }

    cout << ans << endl;
    return 0;
}



/*

https://atcoder.jp/contests/abc137/tasks/abc137_c

content: 
n ogogdon s1..sn hvrtelh 10 urttai string ogogdono tendees anagram string hosuudiig tooloh

timelimit: 2 sec

input/output:
3
acornistnt
peanutbomb
constraint

1

2
oneplustwo
ninemodsix

0

5
abaaaaaaaa
oneplustwo
aaaaaaaaba
twoplusone
aaaabaaaaa

4

*/



