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
typedef vector<string> VS;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
 
int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
void printfv(VI a){ int n = a.size(); FOR(i, n) cout << a[i] << " "; }

int main(void){
    
    // 's', 'sh', 'ch', 'o', 'x' => es
    // 'f', 'fe' => ves
    // y -> !('a', 'i', 'u', 'e', 'o') => ies
   
    int n;
    string str;
    
    cin >> n;
    FOR(i, n){
        cin >> str;
        
        int len = str.length();
        if(str.substr(len-1, 1) == "s" || str.substr(len-1, 1) == "o" || str.substr(len-1, 1) == "x"){
            str.replace(len, 1, "es");
        } else if(str.substr(len-2, 2) == "sh" || str.substr(len-2, 2) == "ch"){
            str.replace(len, 2, "es");
        } else if(str.substr(len-1, 1) == "f"){
            str.replace(len-1, 1, "ves");
        } else if(str.substr(len-2, 2) == "fe"){
            str.replace(len-2, 2, "ves");
        } else if(str.substr(len-1, 1) == "y"){
            if(!(str.substr(len-2, 1) == "a" || str.substr(len-2, 1) == "i" || str.substr(len-2, 1) == "u" || str.substr(len-2, 1) == "e" || str.substr(len-2, 1) == "o")){
                str.replace(len-1, 2, "ies");
            } else {
                str += "s";    
            }
        } else {
            str += "s";
        }
        
        cout << str << endl;
    }
    
    return 0;
}


/*

ogogdson vgiig english iin zov dvrem rvv horvuuleh

input: 
7
box
photo
axis
dish
church
leaf
knife

output: 
boxes
photoes
axises
dishes
churches
leaves
knives

*/