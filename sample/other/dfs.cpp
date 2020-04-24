#include<bits/stdc++.h>

using namespace std;

#define FOR(i,n) for(int i=0; i<n; ++i)

const int  MAX = 25;
int n, m;
char a[MAX][MAX];

void dfs(int i, int j){
	int ii, jj;

	a[i][j] = '.';
	for (int aa = -1; aa <= 1; aa++) {
	    for (int bb = -1; bb <= 1; bb++) {
	    	ii = i + aa;
			jj = j + bb;
			if(ii >= 0 && ii < n && jj >= 0 && jj < m){
				if (a[ii][jj] == 'w') {
					dfs(ii, jj);
		      	}

		    }
	    }
	}

}

int main(void){
    
	cin >> n >> m;

	FOR(i, n){
		FOR(j, m){
			cin >> a[i][j];
		}
	}

	int ans = 0;
	FOR(i, n){
		FOR(j, m){
			if(a[i][j] == '.') continue;

			ans++;
			dfs(i, j);
		}
	}
	cout << ans;

    return 0;
}