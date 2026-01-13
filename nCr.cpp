int n = nums.size();
vector<long long> fact(n+1);
fact[0] = fact[1] = 1;
for(int i=2;i<=n;i++){
    fact[i] = ((i%M)*(fact[i-1]%M))%M;
}

long long C[1001][1001]; 

void build_nCr(int n) {
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
}
