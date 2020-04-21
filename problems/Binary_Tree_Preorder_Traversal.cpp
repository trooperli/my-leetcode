/**
 * This problem can be solved by using either stack DFS or
 * recursion, as shown in solution 1 and 2.
 */



//Solution 1
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {return res;}
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            auto tmp = stk.top();
            stk.pop();
            res.push_back(tmp->val);
            if (tmp->right) {stk.push(tmp->right);}
            if (tmp->left) {stk.push(tmp->left);}
        }
        return res;


    }
};



//Solution 2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {return res;}
        helper(root, res);
        return res;

    }
private:
    TreeNode* helper(TreeNode* root, vector<int> & res) {
        if (root == NULL) {return NULL;}
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
        return root;
    }
};
