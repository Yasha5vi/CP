class AP{
public:
    int N,timer = 0;
    vector<int> vis,tin,low,mark;

    AP(int n):N(n){
        vis.assign(N,0);
        tin.assign(N,0);
        low.assign(N,0);
        mark.assign(N,0);
    }

    void dfs(int node,int parent,vector<vector<int>>& adj){
        vis[node] = 1;
        low[node] = tin[node] = timer++;
        int child = 0;

        for(auto& it:adj[node]){
            if(!vis[it]){
                dfs(it,node,adj);
                low[node] = min(low[node],low[it]);
                // we will take time of node not the lowest here because the point 
                // can have a possibility of removal so taking lowest might not give 
                // give the correct result
                if(low[it] >= tin[node] && parent != -1){
                    mark[node] = 1; 
                }
                child++;
            }else{
                // vis hai and parent bhi hai so no need to update
                if(it == parent) continue;
                low[node] = min(low[node],tin[it]);
            }
        }
        if(child > 1 && parent == -1){
            mark[node] = 1;
        }
    }

    bool hasArticulationPoint(vector<vector<int>>& adj){
        for(int i=0;i<N;i++){
            if(!vis[i]){
                dfs(i,-1,adj);
            }
        }
        for(int i=0;i<N;i++){
            if(mark[i]) return true;
        }
        return false;
    }
};
