#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)
typedef long long ll;

int main(void){
    int n;
    ll temp;

    cin >> n;

    set<ll> unq;
    FOR(i, n){
        cin >> temp;
        unq.insert(temp);
    }

    cout << unq.size();
}
