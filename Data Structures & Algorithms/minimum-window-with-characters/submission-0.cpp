class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }
        unordered_map<char,int> freq;
        for(auto ch : t){
            freq[ch]++;
        }
        int left = 0;
        int required = t.size();
        int minLen = INT_MAX;
        int start = 0;
        for(int right=0; right<s.size(); right++){
            if(freq[s[right]] > 0){
                required--;
            }
            freq[s[right]]--;

            while(required == 0){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }

                freq[s[left]]++;
                if(freq[s[left]] > 0){
                    required++;
                }
                left++;
            }
        }
        if(minLen == INT_MAX){
            return "";
        }
        return s.substr(start,minLen);
    }
};
