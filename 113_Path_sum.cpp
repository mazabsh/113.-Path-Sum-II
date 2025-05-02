#include<iostream> 
#include<vector> 
#include<stack> 


using namespace std; 

struct TreeNode{
    int val; 
    TreeNode *left; 
    TreeNode *right; 
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
}; 

class Solution{
public: 
      vector<vector<int>> res; 

      vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
          vector<int> path; 
          

          dfs(root, path, targerSum); 

          return res; 

      }
      void dfs(TreeNode* root, vector<int> path, int targetSum){

          if(root==nullptr) return; 
          path.push_back(root->val); 
          targetSum -=root->val; 
          if(root->left==nullptr && root->right) {
               if(targetSum==0) res.push_back(path); 
          }else {
              dfs(root->left, path, targetSum); 
              dfs(root->right, path, targetSum); 
          }
      }

};

void printPaths(const vector<vector<int>>& paths) {
    for (const auto& path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Example usage
int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    Solution sol;
    vector<vector<int>> result = sol.pathSum(root, targetSum);
    printPaths(result);

    // Cleanup
    delete root->left->left->left;
    delete root->left->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
