class KMP{
public:
    int subLen;
    vector<int> lps;
    KMP(int n){
        subLen = n;
        lps.resize(subLen);
    }

    void computeLPS(string& sub){
        int curIdx = 1;
        int len = 0;
        while(curIdx < subLen){
            if(sub[curIdx] == sub[len]){
                len++;
                lps[curIdx] = len;
                curIdx++;
            }else{
                if(len > 0){    // backtrack Len
                    len = lps[len-1];
                }else{
                    curIdx++;
                }
            }
        }
    }

    bool search(string& sub,string& main){
        int mainIdx = 0;
        int subIdx = 0;
        
        while(mainIdx < main.size()){
            if(main[mainIdx] == sub[subIdx]){
                mainIdx++;
                subIdx++;
                if(subIdx == subLen){
                    return true;
                }
            }else{
                if(subIdx > 0){
                    subIdx = lps[subIdx-1];
                }else{
                    mainIdx++;
                }
            }
        }
        return false;
    }
};
