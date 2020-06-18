class Solution {
public:
    
    bool inside(vector<vector<char>>& board, int i, int j){
        
        if(i >= 0 && j >= 0 && i < board.size() && j < board[0].size()){
            return 1;
        }
        
        return 0;
    }
    
    void BFS(vector<vector<char>>& board, int i, int j){
        
        queue <pair <int, int> > q;
        q.push({i,j});
        board[i][j] = '2';
        
        while(!q.empty()){
            pair <int, int> temp = q.front();
            q.pop();
            
            if(inside(board,temp.first+1,temp.second) && board[temp.first+1][temp.second] == 'O'){
                q.push({temp.first+1,temp.second});
                board[temp.first+1][temp.second] = '2';
            }
            
            if(inside(board,temp.first-1,temp.second) && board[temp.first-1][temp.second] == 'O'){
                q.push({temp.first-1,temp.second});
                board[temp.first-1][temp.second] = '2';
            }
            
            if(inside(board,temp.first,temp.second+1) && board[temp.first][temp.second+1] == 'O'){
                q.push({temp.first,temp.second+1});
                board[temp.first][temp.second+1] = '2';
            }
            
             if(inside(board,temp.first,temp.second-1) && board[temp.first][temp.second-1] == 'O'){
                q.push({temp.first,temp.second-1});
                board[temp.first][temp.second-1] = '2';
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(board[i][j] == 'O' && (i == 0 || j == 0 || i == board.size()- 1 || j == board[0].size()- 1)){
                    BFS(board, i, j);
                }
            }
        }
        
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[i].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] ='X';
                }
                if(board[i][j] == '2'){
                    board[i][j] ='O';
                }
            }
        }
        
        return;
    }
};
