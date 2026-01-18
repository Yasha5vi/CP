// cond 1 : if overlaps go in both (move in left and right)
// cond 2 : if does not overlaps then go back 
// cond 3 : else if completely lies inside then return the answer from here

class Segtree{
public:
    vector<int> seg;
    vector<int> lazy;

    Segtree(){};
    Segtree(vector<int>& a,int n){
        seg.resize(4*n);
        lazy.resize(4*n);
        build(0,0,n-1,a);
    }

    void build(int idx,int low,int high,vector<int>& a){
        if(low == high){
            seg[idx] = a[low];
            return;
        }
        int mid = (low+high)>>1;
        build(2*idx+1,low,mid,a);
        build(2*idx+2,mid+1,high,a);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }

    void push(int idx){
        if(lazy[idx] != 0){
            seg[2*idx+1] += lazy[idx];
            seg[2*idx+2] += lazy[idx];

            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];

            lazy[idx] = 0;
        }
    }

    void update(int idx,int low,int high,int pos,int v){
        if(low == high){
            seg[idx] = v;
            return;
        }
        int mid = (low+high)>>1;
        if(pos <= mid)    update(2*idx+1,low,mid,pos,v);
        else    update(2*idx+2,mid+1,high,pos,v);
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }

    void range_update(int idx, int low, int high, int l, int r, int v){
        if(l <= low && high <= r){
            seg[idx] += v;
            lazy[idx] += v;
            return;
        }
        if(high < l || r < low) return;

        // partial overlap
        push(idx);
        int mid = (low + high) >> 1;
        range_update(2*idx+1, low, mid, l, r, v);
        range_update(2*idx+2, mid+1, high, l, r, v);
        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }


    int query(int idx,int low,int high,int l,int r){
        if(l <= low && high <= r)    return seg[idx];
        if(high < l || r < low )    return INT_MAX;

        push(idx);
        int mid = (low+high)>>1;
        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);
        return min(left,right);
    }
};
