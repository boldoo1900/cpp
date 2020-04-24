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
 
int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){

    int n, m, k;
    cin >> n >> m >> k;
    
    int *a = new int[n], b[m], index;
    FOR(i, m){
        cin >> index;
        a[index-1] = index;
        b[i] = index;
    }
    
    // FOR(i, n){
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    // FOR(i, m){
    //     cout << b[i] << " ";
    // }
    
    // return 0;
    
    while(k > 0){
        FOR(i, m){
            FORR(j, b[i], 2*n){
                index = j%n;
                //cout << j << endl;
                
                if(a[index] == 0){
                    a[index] = b[i];
                    a[b[i]-1] = 0;
                    b[i] = index+1;
                    break;
                }
            }
            
            // FOR(l, n){
            //     cout << a[l] << " ";
            // }
            // cout << endl;
        }
        
        k--;
    }
    
    FOR(i, m){
        cout << b[i] << endl;
    }
    
    return 0;
}


/*
hooson zaid nar buruu vsreh 

N M K
r_1
r_2
...
r_M

N - niit vsreh bolomjtoi toirguudiin too
M - talbai deer bairlasan tuulain too
K - tuulain niit vsreh too
r_i tuulain bairlal

input: 
6 3 6
1
3
5
 
output: 
1
3
5

garaltand svvliin baidlaar tuulain bairlaliig bichih
*/