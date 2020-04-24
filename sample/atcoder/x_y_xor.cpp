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

// Function to calculate xor 
ll computeXOR(const ll n) 
{ 
    // Modulus operator are expensive on most of the  
    // computers. n & 3 will be equivalent to n % 4.    
  
    switch(n & 3) // n % 4  
    { 
        case 0: return n;     // if n is multiple of 4 
        case 1: return 1;     // If n % 4 gives remainder 1   
        case 2: return n + 1; // If n % 4 gives remainder 2     
        case 3: return 0;     // If n % 4 gives remainder 3   
    } 

    return 0;
}

int main(void){

    ll a,b;
    cin >> a >> b;

    ll ans = computeXOR(a-1)^computeXOR(b);
    cout << ans << endl;
    
    return 0;
}
