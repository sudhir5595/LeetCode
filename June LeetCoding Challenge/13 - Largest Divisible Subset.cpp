class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector <int> res;
        if(nums.size() == 0){
            return res;    
        }
        sort(nums.begin(), nums.end());
        vector <int> div_count(nums.size(), 1);
        vector <int> prev(nums.size(), -1);
        int max_ind = 0;
        
        for(int i = 1; i<nums.size(); i++){
            
            for(int j = 0; j<i; j++){
                
                if(nums[i]%nums[j] == 0){
                    if(div_count[i] < (div_count[j] + 1)){
                        div_count[i] = div_count[j] + 1;
                        prev[i] = j;
                    }
                }
            }
            
            if(div_count[max_ind] < div_count[i]){
                max_ind = i;
            }
        }
        
        while(max_ind >= 0){
            res.push_back(nums[max_ind]);
            max_ind = prev[max_ind];
        }
        
        return res;
    }
};
