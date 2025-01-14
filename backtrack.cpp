void solve(int idx, string& word, int count, vector<int>& split, string& res) {
    if (count < 0) return;
    if(count == 0){
        int pv = 0;
        for(int i=0;i<split.size();i++){
            res = max(res,word.substr(pv,split[i]-pv));
            pv = split[i];
        }
        res = max(res,word.substr(pv,word.size()-pv));
        return;
    }
    for(int i=idx+1;i<word.size();i++){
        split.push_back(i);
        solve(i,word,count-1,split,res);
        split.pop_back();
    }
}
