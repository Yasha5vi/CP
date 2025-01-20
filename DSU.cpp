class Disjoint{
    public:
    
    vi parent,size;
    
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        iota(parent.begin(),parent.end(),0);
    }
    
    int findUlp(int u){
        if(parent[u] == u){
            return u;
        }return parent[u] = findUlp(parent[u]);
    }
    
    void unionBySize(int u,int v){
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
