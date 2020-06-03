class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int res = 0;
        vector < pair <int, int> > diff;
        
        for(int i = 0; i<costs.size(); i++){
            diff.push_back({costs[i][0] - costs[i][1], i});
        }
        
        sort(diff.begin(), diff.end());
        
        for(int i = 0; i<diff.size()/2; i++){
            int temp = diff[i].second;
            res += costs[temp][0];
        }
        
        for(int i = diff.size()/2; i<diff.size(); i++){
            int temp = diff[i].second;
            res += costs[temp][1];
        }
        
        return res;
    }
};
