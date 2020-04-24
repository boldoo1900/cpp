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

    int h,w;
    cin >> h >> w;

    char c[h][w];
    FOR(i, h){
        FOR(j, w){
            cin >> c[i][j]; 
        }
    }

    int i = 0, j = 0, step = 0;
    char direction = 'r';
    while(i >= 0 && j >= 0 && i < h && j < w){
        if(c[i][j] == '\\'){
            switch(direction){
                case 'r': direction = 'd'; break;
                case 'd': direction = 'r'; break;
                case 'u': direction = 'l'; break;
                case 'l': direction = 'u'; break;
            }
        } else if(c[i][j] == '/') {
            switch(direction){
                case 'r': direction = 'u'; break;
                case 'd': direction = 'l'; break;
                case 'u': direction = 'r'; break;
                case 'l': direction = 'd'; break;
            }
        }

        switch(direction){
            case 'r': j++; break;
            case 'd': i++; break;
            case 'u': i--; break;
            case 'l': j--; break;
        }

        ++step;
    }

    cout << step;
    // FOR(i, h){
    //     FOR(j, w){
    //         cout << c[i][j]; 
    //     }

    //     cout << "\n";
    // }

    return 0;

}
