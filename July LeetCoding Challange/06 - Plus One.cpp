class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits[digits.size()-1] < 9){
            digits[digits.size()-1]++;
            return digits;
        }
        vector <int> res;
        int temp = digits[digits.size()-1] + 1;
        int carry = temp/10;
        res.push_back(temp%10);
        for(int i = digits.size()-2; i>=0; i--){
            temp = digits[i] + carry;
            res.push_back(temp%10);
            carry = (digits[i]+carry)/10;
        }
        if(carry != 0){
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
