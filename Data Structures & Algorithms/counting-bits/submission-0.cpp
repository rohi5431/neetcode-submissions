class Solution {
public:
    int cntOne(int n){
        int cnt = 0;
        while(n){
            n = n & (n-1);
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        int cnt = 0;
        for(int i=0; i<=n; i++){
            ans.push_back(cntOne(i));
        }
        return ans;
    }
};
