class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        unordered_map<char,int> freq;

        for(auto ch : s1){
            freq[ch]++;
        }
        int required = s1.size();
        int left = 0;
        for(int right=0; right<s2.size(); right++){
            if(freq[s2[right]] > 0){
                required--;
            }
            freq[s2[right]]--;
            if(right-left+1 > s1.size()){
                if(freq[s2[left]] >= 0){
                    required++;
                }
                freq[s2[left]]++;
                left++;
            }

            if(required == 0){
                return true;
            }
        }
        return false;
    }
};
