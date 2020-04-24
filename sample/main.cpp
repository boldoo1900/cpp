#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
typedef long long ll;

int n, m = 100;
ll a[100000];

int main(void){
    cin >> n;
    
    ll ans = 0;
    FOR(i, n){
        cin >> a[i];
    }
    sort(a, a+n);
    
    FOR(i, n){
		ans += (a+n) - lower_bound(a, a+n, m - a[i]);
    }
    
    cout << ans;
    return 0;
}
