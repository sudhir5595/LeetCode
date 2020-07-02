/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector < vector <int> > res;
        queue <TreeNode*> q1;
        queue <TreeNode*> q2;
        if(root == NULL){
            return res;
        }
        q1.push(root);
        vector <int> buffer;
        int temp = 0;
        
        while(temp == 0){
            while(q1.size() != 0){
                buffer.push_back(q1.front()->val);
                if(q1.front()->left != NULL){
                    q2.push(q1.front()->left);
                }
                if(q1.front()->right != NULL){
                    q2.push(q1.front()->right);
                }
                q1.pop();
            }
            
            if(buffer.size() != 0){
                res.push_back(buffer);
                buffer.clear();
            }
            
            while(q2.size() != 0){
                buffer.push_back(q2.front()->val);
                if(q2.front()->left != NULL){
                    q1.push(q2.front()->left);
                }
                if(q2.front()->right != NULL){
                    q1.push(q2.front()->right);
                }
                q2.pop();
            }
            
            if(buffer.size() != 0){
                res.push_back(buffer);
                buffer.clear();
            }
            
            if(q1.size() == 0 && q2.size() == 0){
                temp = 1;
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
