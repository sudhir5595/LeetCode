class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int count_zero = 0;
        int count_one = 0;
        int count_two = 0;
        
        for(int i = 0; i<nums.size(); i++){
            
            if(nums[i] == 0){
                count_zero++;
            }
            else if(nums[i] == 1){
                count_one++;
            }
            else{
                count_two++;
            }
        }
       
        for(int i = 0; i<nums.size(); i++){
            if(i < count_zero){
                nums[i] = 0;
            }
            else if(count_zero <= i && i < (count_one + count_zero)){
                nums[i] = 1;
            }
            else{
                nums[i] = 2;
            }
        }
        
        return;
    }
};
