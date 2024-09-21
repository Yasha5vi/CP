// Radhe Radhe

#include <bits/stdc++.h>
using namespace std;

// Type Definitions
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pll> vpl;

// Constants
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e18;

#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define repv(i, a, b) for (ll i = (a); i >= (b); --i)
#define sortAll(a) sort(a.begin(), a.end())
#define revAll(a) reverse(a.begin(), a.end())
#define sumAll(a) accumulate(a.begin(), a.end(), 0LL)

template<typename T>
bool isSorted(T ar)
{rep(i,1,(int)ar.size()){if(ar[i]<ar[i-1])return false;}return true;}

bool even(ll a){ return a%2==0;}
// Function to calculate GCD
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
// Function to check prime
auto isPrime = [](int n) -> bool {
    return n > 1 && (n == 2 || n == 3 || (n % 2 != 0 && n % 3 != 0 && [n]{
        for (int i = 5; i * i <= n; i += 6) 
            if (n % i == 0 || n % (i + 2) == 0) 
                return false; 
        return true;
    }()));
};

template<typename T>
void print(const vector<T> &arr) {
    for (const auto &val : arr) {
        cout << val << " ";
    }
    cout << "\n";
}

template<typename T>
void inp(vector<T> &arr, ll n) {
    arr.resize(n);
    rep(i, 0, n) {
        cin >> arr[i];
    }
}
template<typename T>
void inPair(vector<T> &arr, ll n) {
    ll a,b;
    rep(i, 0, n) {
    	cin>>a>>b;
        arr.push_back({a,b});
    }
}

#define debug(x) cerr << #x << " = " << x << '\n'
#define debugArray(arr) cerr << #arr << " = "; prllArray(arr)

class Disjoint{
    public:
    
    vi parent,size,cnt;
    
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        cnt.resize(n+1,0);
        iota(parent.begin(),parent.end(),0);
    }
    
    int findUlp(int u){
        if(parent[u] == u){
            return u;
        }return parent[u] = findUlp(parent[u]);
    }
    
    void unionSize(int u,int v,string col){
        int ulp = findUlp(u);
        int vlp = findUlp(v);
        
        if(ulp == vlp) return;
        
        if(size[ulp] < size[vlp]){
            size[vlp]+=size[ulp];
            parent[ulp] = vlp;
        }else{
            size[ulp]+=size[vlp];
            parent[vlp] = ulp;
        }
    }
};
