#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
#define FORR(i,a,n) for(int i=a; i<n; ++i)
#define ALL(c) (c).begin(), (c).end()

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

// h w geer ogogdson rectangle aas 2 2 hemjeest toonuud l bgaa oldson toonuudiig tootsooloh
int main(void){

    int h,w;
    cin >> h >> w;
    
    int **a = new int*[h];
    for(int i = 0; i < h; ++i) {
        a[i] = new int[w];
    }
    
    cin >> a[0][0] >> a[0][1] >> a[1][0] >> a[1][1];
    
    FORR(j, 2, w){
        a[0][j] = a[0][j-1]+(a[0][1] - a[0][0]);
        a[1][j] = a[1][j-1]+(a[1][1] - a[1][0]);
    }
    
    FORR(i, 2, h){
        FOR(j, w){
            a[i][j] = a[i-1][j] + (a[1][j]-a[0][j]);
        }
    }
    
    FOR(i, h){
        FOR(j, w){
            cout << a[i][j];
            if(j != w-1)
                cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}


/*
too 2x2 hartsaatai ogogdono tendees vldsen toonuudiig oloh
shiidel: ehleed ehnii 2 moriig tootsoolood daraa ni doosh bodoh zarchmaar

a_{i, j} = a_{i, j - 1} + (a_{i, 2} - a_{i, 1}) ※ 任意の行が等差数列になっている事を示します
a_{i, j} = a_{i - 1, j} + (a_{2, j} - a_{1, j}) ※ 任意の列が等差数列になっている事を示します

structure:
a_{1, 1} a_{1, 2} ... a_{1, W}
a_{2, 1} a_{2, 2} ... a_{2, W}
...
a_{H, 1} a_{H, 2} ... a_{H, W}

input:
5 5
1 2
3 4

output:
1 2 3 4 5
3 4 5 6 7
5 6 7 8 9
7 8 9 10 11
9 10 11 12 13

*/