#include<bits/stdc++.h>

using namespace std;

#define FOR(i,a,n) for(int i=a; i<n; ++i)
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
void printfv(VI a){ int n = a.size(); FOR(i, 0, n) cout << a[i] << " "; cout << endl; }

int main(void){

    int m,n,k, vote;
    cin >> m >> n >> k;

    VI votes(m, 0);
    FOR(i, 0, k){
        cin >> vote;

        int plus = 0;
        FOR(j, 0, m){
            if(votes[j] != 0 && vote != j+1){
                votes[j] -= 1;
                plus += 1;
            }
        }

        if(n > 0){
            votes[vote-1] += 1+plus;
            n--;
        } else {
            votes[vote-1] += plus;
        }

        //printfv(votes);
    }
    
    sort(ALL(votes));
    int max = votes[m-1];
    FOR(i, 0, m){
        if(votes[i] == max){
            cout << (i+1) << endl; 
        }
    }

    return 0;
}


/*
songuul ner devshigchid neg negeer garch yriltslaga hiine ter bolgond sanal ogogchid 
neg negeer nemegdene

M N K
a_1
a_2
...
a_K

M は立候補者の人数を、N は有権者の人数を、K は演説が行われる回数
i 番目の演説が a_i 番目の立候補者によってされたことを表しています。 

すべての演説が終わった後、最も支持者が多い立候補者の番号を出力してください。

input example:
3 3 4
1
1
2
3

output example:
3

*/