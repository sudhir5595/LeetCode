class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int res = 0;
        int final_res = 0;
        for(int i = citations.size()-1; i>=0; i--){
            int temp = citations.size() - i;
            res = min(citations[i], temp);
            if(final_res < res){
                final_res = res;
            }
        }
        
        return final_res;
    }
};
