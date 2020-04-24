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
//void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){

  int w, h, x, y;
  cin>> w >> h >> x >>y;

  cout<<(double)w*h/2.0<<" "<<(x*2==w&&y*2==h)<<endl;

  return 0;
}


/*
https://atcoder.jp/contests/abc130/tasks/abc130_c?lang=ja

detail:
	ogogdson rectangle iin haanch hamaagui neg tseg ogodono ter tsegeer damjuulan 
	rectangle iig zvselt hiih tendees max bolon min talbain zorvv hamgiin baga bh
	max hesgiin utgiig hevleh
	ter max iig neg l zvselteer gargaj avah bol 0, esreg tohioldol 1 hevleh

solution:
	yag talaar ni huvaaval zorvv 0 bolno. ymar ch tseg bsan toviin tsegtei holbohod 
	talaar huvaagdana.
	herev goliin tseg bish l bol busad tohioldold gants l zvselt hiigdene

input:  2 3 1 2
output: 3.000000 0

input:   2 2 1 1
output:  2.000000 1

*/



