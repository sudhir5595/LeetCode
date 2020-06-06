class Solution {
public:
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        if(people.size() <= 1){
            return people;
        }
        
        vector<vector<int>> result(people.size(), vector <int> (2,INT_MAX));
        
        sort(people.begin(), people.end());
        
        result[people[0][1]] = people[0];
        
        for(int i = 1; i<people.size(); i++){
            int temp = people[i][1];
            int counter = 0;
            int index = 0;
            
            while(counter != temp){

                if(result[index][0] >= people[i][0]){
                    counter++;
                }

                index++;
            }
            
            while(result[index][0] != INT_MAX){
                index++;
            }
            result[index] = people[i];
        }   
        return result;
   
    }
};
