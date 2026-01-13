const int M = 1e9+7;

ll power(ll a,ll b){
    ll res=1;   
    while(b){
        if(b&1)res=(res*a)%M;
        a=(a*a)%M;
        b>>=1;
    }
    return res;
}
