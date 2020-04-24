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
    
    int n,x;
    cin >> n >> x;
    
    VI a;
    int a_i, b_i, c_i, d_i, fare;
    
    FOR(i, n){
        cin >> a_i >> b_i >> c_i >> d_i;
        
        if(x == a_i){
            fare = b_i+d_i;
        } else if(x-a_i > 0){
            if((x-a_i)%c_i == 0){
                fare = (x-a_i)/c_i*d_i+b_i+d_i;
            } else {
                fare = (x-a_i)/c_i*d_i+b_i+d_i;    
            }
        } else{
            fare = b_i;
        }
        
        a.push_back(fare);
    }
    
    sort(ALL(a));
    cout << a.front() << " " << a.back();
    
    return 0;
}

/*
taxi nii tolbor

input:
N X
a_1 b_1 c_1 d_1
a_2 b_2 c_2 d_2
...
a_N b_N c_N d_N

output:
P_1 P_2


N - taxi nii torol
X - ochih gazar hvrtelh zai

a_i - 初乗り距離
b_i - 初乗り運賃
c_i - 加算距離
d_i - 加算運賃

P_1 P_2 - タクシーの料金の最安値と最高値

input:
2 700
600 200 200 400
900 800 400 500

output:
600 800

*/
