
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//descending
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) {
    return (a.second > b.second);
}

int mainVP(void){

    int n, s, p, tol, err;
    vector<pair<int, int>> arr;

    cin >> n >> s >> p;
    for(int i=0; i < n; i++){
        cin >> tol >> err;

        if((s-p) <= err && err <= (s+p))
            arr.push_back(make_pair(i, tol));
    }

    if(arr.size() == 0){
        cout << "not found" << endl;
    } else {
        sort(arr.begin(), arr.end(), sortbysec);
        cout << arr[0].first+1;
    }

    return 0;
}
