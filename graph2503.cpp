#define pi pair<int,int>
#define vi vector<int>

typedef struct node{
    int val;
    int r;
    int c;
    node(int v, int row, int col) : val(v), r(row), c(col) {}
}node;

struct Compare{
    bool operator()(const node& a,const node& b){
        return a.val > b.val;
    }
};

class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pi> ar;
        int nq = queries.size();
        for(int i=0;i<nq;i++){
            ar.push_back({queries[i],i});
        } 
        sort(ar.begin(),ar.end());

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,-1,0,1};
        int n = grid.size();
        int m = grid[0].size();

        vi res(nq,0);
        vector<vi> vis(n,vector<int>(m,0));
    
        priority_queue<node,vector<node>,Compare> pq;
        int cnt = 0;
        pq.push(node(grid[0][0],0,0));

        for(auto& [x,idx]:ar){
            while(!pq.empty() && pq.top().val < x){
                auto it = pq.top();
                int val = it.val;
                int r = it.r;
                int c = it.c;
                pq.pop();

                if(vis[r][c]) continue;
                vis[r][c] = 1;
                cnt++;

                for(int i=0;i<4;i++){
                    int nr = r+delRow[i];
                    int nc = c+delCol[i];
                    if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc]){
                        pq.push(node(grid[nr][nc],nr,nc));
                    }
                }
            }
            res[idx] = cnt;
        }
        return res;
    }
};
