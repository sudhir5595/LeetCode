class Solution {
public:
    int hammingDistance(int x, int y) {
        int answer=0;
        while(x||y){  //checking for atleast one of them is positive
            
            if(x&&y){  //if both x and y are positive
                if(x%2!=y%2) answer++;
                x/=2;
                y/=2;
            }
            else if(x){  //if control comes over there that means one of them become 0, checking if x is positive then continue
                if(x%2) answer++;
                x/=2;
            }
            else{  //else we only left with y and x becomes 0
                if(y%2) answer++;
                y/=2;
            }
        }
        return answer;
    }
};
