
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V,0);
    vector<int> ans;
    stack<int> st;

    auto dfs = [&](auto& self,int node)->void{
        vis[node] = 1; 
        for(auto it:adj[node]){
            if(!vis[it]){
                self(self,it);
            }
        }
        st.push(node);
    };

    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(dfs,i);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}
