class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        
        if(N%14 == 0){
            N = 14;
        }
        else{
            N = N%14;
        }
        vector<int> cells2(8,0); 
        
        while(N>0){
            for(int i=1;i<cells.size()-1;i++){
                if(cells[i-1] == cells[i+1]){
                cells2[i] = 1;
                }
                else{
                    cells2[i] = 0;
                }
            }
            cells = cells2;
            N--;
        }
        
        return cells;
    }
    
};
