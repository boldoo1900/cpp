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
 
template<typename T> bool mmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }


int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){

    int h,w, n;
    cin >> h >> w >> n;

    char c[h][w];

    FOR(i, h){
        FOR(j, w){
            c[i][j] = '.'; 
        }
    }

    int h_i, w_i, x_i;
    FOR(ii, n){
        cin >> h_i >> w_i >> x_i;

        int ypos = 0, xcount = 0;
        // find start postion
        for(int i = h-1; i>= 0; i--){
            for(int j = x_i; j < x_i+w_i; j++){
                if(c[i][j] == '#'){
                    ypos = i+1;
                    i = 0;
                    break;
                }
            }
        }

        for(int i = ypos; i < h; i++){
            if(xcount == h_i) break;

            for(int j = x_i; j < x_i+w_i; j++){
                c[i][j] = '#';
            }

            xcount++;
        }

    }


    FOR(i, h){
        FOR(j, w){
            cout << c[h-i-1][j]; 
        }
        cout << "\n";
    }

    return 0;

}

// A017:落ちものシミュレーション
// input:
// 7 10 4
// 1 8 1
// 4 1 5
// 1 6 2
// 2 2 0

// output:
// ..........
// ..######..
// .....#....
// .....#....
// ##...#....
// ##...#....
// .########.

