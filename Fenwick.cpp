
class FenwickTree {
public:
    vector<ll> fen; ll n; 
    FenwickTree(ll size) {
        n = size;
        fen.assign(n+1,0);;
    }
    void build(vector<ll>& arr) {
        for (ll i = 0; i < n; i++) {
            update(i + 1, arr[i]);
        }
    }
    void update(ll idx, ll val) {
        while (idx <= n) {
            fen[idx] += val;
            idx = idx+(idx&(-idx)); 
        }
    }
    ll sum(ll idx) {
        ll res = 0;
        while (idx > 0) {
            res += fen[idx];
            idx = idx-(idx&(-idx)); 
        }return res;
    }
    ll rangeSum(ll left,ll right) {
        return sum(right) - sum(left - 1);
    }
};
