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
    ios::sync_with_stdio(false);

    int n, x;    
    cin >> n;

    vector<PI> v;
    FOR(i, n){
        cin >> x;
        v.push_back({x, i+1});
    }

    sort(ALL(v));
    for(PI p:v){
        cout << p.second << " ";
    }

    return 0;
}


/*

https://atcoder.jp/contests/abc142/tasks/abc142_c
"VECTOR & PAIR IIN HEREGLEE"

bodlogo: 
1 <= N <= POW(10,5)  - NIIT SURAGCHDIIN TOO
1 <= Ai <= N         - I DAHI SURAGCHIID ANGID ORJ IRHED BSAN SURAGCHDIIN TOO

SURAGCHDIIN ANGID ORJ IRSEN DARAALLIIG HEVLEH
INPUT STRUCTURE:
N
A1 A2 ... An

INPUT:
3
2 3 1


OUTPUT:
3 1 2


*/





