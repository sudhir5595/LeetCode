class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return 0;
        }
        
        if(target < nums[0] || nums[nums.size() - 1] < target){
            if(target < nums[0]){
                return 0;
            }
            else{
                return nums.size();
            }
        }
        
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end){
            
            int mid = start + (end - start)/2;
           
            if(nums[mid] == target){
                return mid;
            }
            if(nums[mid] < target && nums[mid + 1] > target){
                return mid+1;
            }
            else if(nums[mid] < target){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
            
        }
        
        return -1;
    }
    
};
