#define ll long long
const int M = 1e9 + 7;

typedef struct node{
    int idx;
    int score;
    int x;
    ll range;
    node(int a,int e,int b,ll c) : idx(a),x(e),score(b),range(c){}
}node;

class Solution {
public:
    vector<bool> isPrime;
    vector<int> prime;
    void seive(int n){
        isPrime.resize(n+1,true);
        for (int p = 2; p * p <= n; p++) {
            if (isPrime[p] == true) {
                prime.push_back(p);
                for (ll i = (ll) p * p; i <= n; i += p)
                    isPrime[i] = false;
            }
        }
    }
    vector<int> calculate_score(vector<int>& nums){
        int n = nums.size();
        vector<int> score(n,0);
        for(int i=0;i<n;i++){
            int x = nums[i];
            for(int p:prime){
                if(p*p > x) break;
                if(x%p != 0) continue;
                score[i]++;
                while(x%p == 0){
                    x/=p;
                }
            }
            if(x > 1) score[i]++;
        }
        return score;
    }

    ll mod_pow(ll base, ll exp) {
        ll result = 1;
        base = base % M; 
        while (exp > 0) {
            if (exp & 1LL) {         
                result = (result * base) % M;
            }
            base = (base * base) % M;     
            exp >>= 1;             
        }
        return result;
    }
    int maximumScore(vector<int>& nums, int k) {
        seive(*max_element(nums.begin(),nums.end()));
        vector<int> score = calculate_score(nums);

        int n = nums.size();
        vector<int>left(n,-1),right(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && score[st.top()] < score[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            right[st.top()] = n;
            st.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && score[st.top()] <= score[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            left[st.top()] = -1;
            st.pop();
        }
        // for(auto it:left) cout<<it<<" ";cout<<endl;
        // for(auto it:right) cout<<it<<" ";cout<<endl; 
//         -1 -1 1 1 3 -1 5 -1 7 8 8 10 11 12 12 14 14 16 17 17 17 20 21 20 23 16 25 25 27 28 27 25 31 32 33 31 35 31 37 31 39 40 39 42 42 42 45 
// 1 5 3 5 5 7 7 47 47 10 47 47 47 14 47 16 47 25 19 20 25 23 23 25 25 47 27 31 30 30 31 47 35 35 35 37 37 39 39 47 42 42 47 44 45 47 47 
        vector<node> a;
        for(int i=0;i<n;i++){
            ll range = (ll)(i-left[i])*(right[i]-i);
            a.push_back(node(i,nums[i],score[i],range));
        }

        sort(a.begin(),a.end(),[&](node& a,node& b){
            return a.x > b.x;
        });
        // for(auto it:a)cout<<it.idx<<" "<<it.x<<" "<<it.score<<" "<<it.range<<endl;
        ll res = 1;
        for(auto it:a){
            ll times = min(it.range,(ll)k);
            // cout<<it.x<<" "<<times<<endl;
            res = ((res%M)*(mod_pow(it.x,times)%M))%M;
            k -= times;
            if(k<=0){   
                break;
            }
        }
        // cout<<res<<endl;
        return res;
    }
};
