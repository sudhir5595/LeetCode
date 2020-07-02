class Solution {
public:
    int arrangeCoins(int n) {
        int res = 0;
        int temp = 1;
        while(n > 0){
            n = n - temp;
            temp++;
            res++;
        }
        if( n < 0){
            res--;
        }
        return res;
    }
};
