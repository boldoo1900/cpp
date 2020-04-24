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
 
//int in() { int x; scanf("%d", &x); return x; }
//ll lin() { ll x; scanf("%lld", &x); return x; }
void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){

	ll a,b,c,d;
	cin >> a >> b >> c >> d;

	ll sum1=b/c-(a-1)/c;				// c giin a aas b giin hoorondoh huvaagchdiin too
	ll sum2=b/d-(a-1)/d;				// d giin a aas b giin hoorondoh huvaagchdiin too
	ll lcm=c*d/__gcd(c,d);
	ll sum3=b/lcm-(a-1)/lcm;			// c d 2 iin ali alind ni huvaagdagchdiin too

	cout<<(b-a+1)-(sum1+sum2-sum3)<<'\n';	// sum1+sum2 iig nemeed niitleg huvaagchiig hasaad oghod c, d 2 t ali alind ni huvaagddag toonuud l vldene

    return 0;
}

/*
2019-06-22
https://atcoder.jp/contests/abc131/tasks/abc131_c

problem statement
	a b c d 4 too garaas ogogdono a b 2 iin hoorondoh c esvel d d huvaagddaggui dugaaruudiin toog oloh


input
	4 9 2 3
	10 40 6 8
	314159265358979323 846264338327950288 419716939 937510582

output
	2
	23
	532105071133627368
*/







