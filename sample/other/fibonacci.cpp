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

ll mod = (1e+9 + 7);
const ll MAX = 100; 
ll f[MAX] = {0}; 

ll fib(int n)
{
    if (n == 0) 
        return 0; 
    if (n == 1 || n == 2) 
        return (f[n] = 1); 
  
    if (f[n]) 
        return f[n]; 
  
    int k = (n & 1)? (n+1)/2 : n/2; 
  
    f[n] = ((n & 1)? (fib(k)*fib(k) + fib(k-1)*fib(k-1)) 
           : (2*fib(k-1) + fib(k))*fib(k)) % mod; 
  
    return f[n]; 
}

int main(void){
    
	int n;
	cin >> n;

	cout << fib(n);

    return 0;
}


// https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/