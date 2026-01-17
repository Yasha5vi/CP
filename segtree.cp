/ cond 1 : if overlaps go in both (move in left and right)
// cond 2 : if does not overlaps then go back 
// cond 3 : else if completely lies inside then return the answer from here

class Segtree{
public:
    vector<int> seg;
    vector<int> lazy;

    Segtree(){};
    Segtree(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int idx,int low,int high,vector<int>& a){
        // cout<<low<<" "<<high<<" "<<idx<<endl;
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
            // apply to children
            seg[2*idx+1] += lazy[idx];
            seg[2*idx+2] += lazy[idx];

            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];

            lazy[idx] = 0;
        }
    }

    // point update
    void update(int idx,int low,int high,int pos,int v){
        if(low == high){
            seg[idx] = v;
            return;
        }
        // else overlaps
        int mid = (low+high)>>1;
        if(pos <= mid){
            update(2*idx+1,low,mid,pos,v);
        }else{
            update(2*idx+2,mid+1,high,pos,v);
        }
        seg[idx] = min(seg[2*idx+1],seg[2*idx+2]);
    }

    void range_update(int idx, int low, int high, int l, int r, int v){
        // complete overlap
        if(l <= low && high <= r){
            seg[idx] += v;
            lazy[idx] += v;
            return;
        }
        // no overlap
        if(high < l || r < low) return;

        // partial overlap
        push(idx);

        int mid = (low + high) >> 1;
        range_update(2*idx+1, low, mid, l, r, v);
        range_update(2*idx+2, mid+1, high, l, r, v);

        seg[idx] = min(seg[2*idx+1], seg[2*idx+2]);
    }


    int query(int idx,int low,int high,int l,int r){
        if(l <= low && high <= r){
            // completely lies inside
            return seg[idx];
        }
        if(high < l || r < low ){
            // does not overlap
            return INT_MAX;
        }
        push(idx);
        // overlaps
        int mid = (low+high)>>1;
        int left = query(2*idx+1,low,mid,l,r);
        int right = query(2*idx+2,mid+1,high,l,r);
        return min(left,right);
    }
};
