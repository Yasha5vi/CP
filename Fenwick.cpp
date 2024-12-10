class FenwickTree {
public:
    vector<long long> fen;
    int n; 
    FenwickTree(int size) {
        n = size;
        fen.assign(n+1,0);;
    }
    void build(vector<ling long>& arr) {
        for (int i = 0; i < n; i++) {
            update(i + 1, arr[i]);
        }
    }
    void update(int idx,int val) {
        while (idx <= n) {
            fen[idx] += val;
            idx = idx+(idx&(-idx)); 
        }
    }
    long long sum(int idx) {
        long long res = 0;
        while (idx > 0) {
            res += fen[idx];
            idx = idx-(idx&(-idx)); 
        }return res;
    }
    long long rangeSum(int left,int right) {
        return sum(right) - sum(left - 1);
    }
};

// 2D
class FenwickTree {
public:
    vector<vector<long long>> fen; 
    int n,m; 
    FenwickTree(int r,int c) {
        n = r;
        m = c;
        fen.assign(n + 1, vector<long long>(m + 1, 0));
    }
    void update(int x, int y, int val) {
        for (int i = x; i <= n; i += (i & -i)) {
            for (int j = y; j <= m; j += (j & -j)) {
                fen[i][j] += val;
            }
        }
    }
    void build(const vector<vector<long long>>& matrix) {
        for (int i = 1; i <= n; ++i) {
            for(int j = 1; j <= m; ++j) {
                update(i, j, matrix[i - 1][j - 1]); 
            }
        }
    }
    long long query(int x, int y) {  // sum
        long long sum = 0;
        for (int i = x; i > 0; i -= (i & -i)) {
            for (int j = y; j > 0; j -= (j & -j)) {
                sum += fen[i][j];
            }
        }
        return sum;
    }
    long long rangeQuery(int x1, int y1, int x2, int y2) { // rangeSum
        return query(x2,y2) + query(x1-1,y1-1) - query(x1-1,y2) - query(x2,y1-1) ;
    }
};
