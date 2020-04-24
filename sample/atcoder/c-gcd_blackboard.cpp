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
	// cin.tie(nullptr);
	// ios::sync_with_stdio(false);

	int n;
	cin >> n;

	ll a[n], l[n + 1], r[n + 1];
	ll ans = 0;
	
	FOR(i,n) {
		cin >> a[i];
	}

	l[0] = 0;
	for (int i = 0; i < n; i++) {
		//cout << l[i] << " " << a[i] << " ";
		l[i + 1] = __gcd(l[i], a[i]);
		//cout << l[i+1] << '\n';
	}

	r[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		//cout << r[i] << " " << a[i] << " ";
		r[i] = __gcd(r[i + 1], a[i]);
		//cout << r[i] << '\n';
	}
 
	// FOR(i, n+1){
	// 	cout << l[i] << " ";
	// }
	// cout << endl;
	// FOR(i, n+1){
	// 	cout << r[i] << " ";
	// }
	// cout << endl;

 	FOR(i, n){
		ans = max(ans, __gcd(l[i], r[i + 1]));
		cout << ans << " " << l[i] << " " << r[i+1] << endl;
	}

	cout << ans;
	return 0;
}


/*
https://atcoder.jp/contests/abc125/tasks/abc125_c
https://img.atcoder.jp/abc125/editorial.pdf

n array element given. U can change only one element after that find 
the gcd(greatest common divisor) from array

input:
N
A1...AN

output:
gcd

example input:
3
7 6 8

example output:
2

*/