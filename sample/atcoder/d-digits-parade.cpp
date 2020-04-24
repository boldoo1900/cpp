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

const int INF = 0x3f3f3f3f;
const ll MOD = 1000000007LL;

//int in() { int x; scanf("%d", &x); return x; }
//ll lin() { ll x; scanf("%lld", &x); return x; }
//void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){
    const int m = 13;
    int n;
    int dp[m] = {};
    string s;
    cin >> s;

    n = s.size();
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        int nextDP[m] = {};

        FOR(j, m){      // 0 - 12 toonuudaar hvsnegt vvsgeh 
            if(s[i] == '?'){
                FOR(k, 10){     // 0 - 9 tsifrvvd
                    nextDP[(j*10+k)%m] += dp[j];
                    nextDP[(j*10+k)%m] %= MOD;      // het ih hemjeenii toog bagasgahiin tuld
                }
            } else {
                int k = s[i] - '0';        // string iig char aar guilgehed bvgd ascii bh uchir ('9' - '0') = (57 − 48) = 9
                nextDP[(j*10+k)%m] += dp[j];
                //nextDP[(j*10+k)%m] %= MOD;

                cout << (j*10+k) << " (" << (j*10+k)%m << ") ";
            }
        }

        cout << endl;
        FOR(j, m){
            cout << nextDP[j] << " ";
        }
        cout << endl << endl;

        swap(dp, nextDP);
    }

    cout << endl;
    FOR(j, m){
        cout << dp[j] << " ";
    }
    //cout << dp[5];

    return 0;
}

/*

https://atcoder.jp/contests/abc135/tasks/abc135_d?lang=ja

ex: 1?2?5 zagvartai string ogogdono endees 13 t huvaagaad 5 vldeh heden too bgaag tooloh

*/


