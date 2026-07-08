class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());

        int remove = 0;
        int end = intervals[0][1];

        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= end){
                // no overlap
                end = intervals[i][1];
            }
            else{
                // overlap
                remove++;
                end = min(end,intervals[i][1]);
            }
        }
        return remove;
    }
};
