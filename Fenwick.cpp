class FenwickTree {
private:
    vector<ll> fen; 
    ll n; 
public:
    FenwickTree(int size) {
        n = size;
        memset(fen, 0, sizeof(fen));
    }

    void update(int idx, ll val) {
        while (idx <= n) {
            fen[idx] += val;
            idx += (idx & (-idx)); 
        }
    }

    ll sum(int idx) {
        ll sum = 0;
        while (idx > 0) {
            res += fen[idx];
            idx -= (idx & (-idx)); 
        }
        return res;
    }

    ll rangeSum(int left, int right) {
        return sum(right) - sum(left - 1);
    }
};
