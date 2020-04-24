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

int main(void){
    
    int h,w,n,l;
    cin >> h >> w >> n;

    int a[h][w], *player = new int[n];
    FOR(i, h){
        FOR(j, w){
            cin >> a[i][j];
        }
    }
    
    cin >> l;
    int h_1, w_1, h_2, w_2, order = 0; 
    FOR(i, l){
        cin >> h_1 >> w_1 >> h_2 >> w_2;
        
        if(a[h_1-1][w_1-1] == a[h_2-1][w_2-1]){
            player[order] += 2;            
        } else {
            if(order == n-1)
                order = 0;
            else
                order++;
        }
    }

    //sort(player, player+n);    
    FOR(i, n){
        cout << player[i] << endl;
    }
    
    return 0;
}


/*
card sugalah togloom card iig 2 iig sugalaad ijil bval ooriin bolgoj onoogoo
nemegdvvleed dahin sugalah ijil bish bval daraagiin hvn sugalah

input:
H W N
t_{1,1} t_{1,2} ... t_{1,W}
t_{2,1} t_{2,2} ... t_{2,W}
...
t_{H,1} t_{H,2} ... t_{H,W}
L
a_1 b_1 A_1 B_1
a_2 b_2 A_2 B_2
...
a_L b_L A_L B_L

1行目には3つの整数 H, W, Nが入力されます。 H と W はそれぞれ並べられたトランプの縦方向の枚数と横方向の枚数で、 N はプレイヤーの数を表します。

続く H 行には、配置されたトランプに書かれた数字が入力されます。 t_{i,j} は i 行 j 列に置かれたトランプに書かれた数字を表します。

次の行には、記録の長さ L が与えられます。

続く L 行には、捲られたトランプの記録が時系列順で与えられます。 これは、a_i 行 b_i 列のトランプと A_i 行 B_i 列のトランプが捲られたことを表します。

output: 
s_1
s_2
...
s_N

s_i は i 番目のプレイヤーが取り除いたトランプの枚数を表します。 各行の最後は改行し、余計な文字、空行を含んではいけません。

input example:
2 2 2
1 2
2 1
4
1 1 2 1
1 1 1 2
1 1 2 2
1 2 2 1

output example:
4
0

*/