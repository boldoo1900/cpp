#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){


    int s, t, spot;
    ll val;
    vector<ll> arrS, arrT;

    cin >> s >> t >> spot;
    for(int i = 0; i < s; i++){
        cin >> val;
        arrS.push_back(val);
    }

    for(int i = 0; i < t; i++){
        cin >> val;
        arrT.push_back(val);
    }

    // lower_bound ashiglah ved hamgiin ehnii esvel svvliinh baij boloh uchraas -+ utga ehlel togsgold nemeh
    arrS.push_back(-1e17);
    arrS.push_back(1e17);
    arrT.push_back(-1e17);
    arrT.push_back(1e17);
    sort(arrS.begin(), arrS.end());
    sort(arrT.begin(), arrT.end());

    for(int i = 0; i < spot; i++){
        ll ans = 1e18;
        cin >> val;

        int ii=lower_bound(arrS.begin(),arrS.end(), val)-arrS.begin();
        int jj=lower_bound(arrT.begin(),arrT.end(), val)-arrT.begin();

        ll ra = arrS[ii] - val;     
        ll rb = arrT[jj] - val;
        ll la = val - arrS[ii - 1];
        ll lb = val - arrT[jj - 1];

        // cout << ra << rb << endl;
        // cout << la << lb << endl;
        // cout << ans << endl;
        // ogogdson tseg ni hamag svvld esvel hamgiin ehend bh ved ehnii 2 tootsoolloor
        ans = min(ans, max(ra, rb));
        ans = min(ans, max(la, lb));

        // tseg ni shrine temple 2 iin dund bh ved
        ans = min(ans, ra + lb + min(ra, lb));
        ans = min(ans, la + rb + min(la, rb));

        cout << ans << endl;
    }

    return 0;
}
