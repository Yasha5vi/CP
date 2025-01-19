int n = nums.size();
vector<long long> fact(n+1);
fact[0] = fact[1] = 1;
for(int i=2;i<=n;i++){
    fact[i] = ((i%M)*(fact[i-1]%M))%M;
}

vector<vector<long long>> ncr(n+1,vector<long long>(101));
ncr[0][0] = 1;
for(int i=1;i<=n;i++){
    ncr[i][0] = 1;
    if(i<=k){
        ncr[0][i] = 0;
    }
}
// nCr = (n-1)Cr + (n-1)C(r-1)
for(int i=1;i<=n;i++){
    for(int j=1;j<=min(100,i);j++){
        ncr[i][j] = (ncr[i-1][j]%M + ncr[i-1][j-1]%M)%M;
    }
}
