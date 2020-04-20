/**
 * We use recursion here. BST binary search tree is a special binary
 * tree.Left child is smaller while right child is larger.
 * Basically we use the lower and upper bound to see whether a
 * node can be created.If a node can be created, we call recursively
 * of the left and right child.
 */



class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        n = preorder.size();
        preorder_ = preorder;
        return helper(INT_MIN, INT_MAX);
    }
private:
    TreeNode* helper(int lower, int upper) {
        if (idx == n) return NULL;
        int val = preorder_[idx];
        if (val < lower || val > upper) {return NULL;}
        idx++;
        TreeNode* root = new TreeNode(val);
        root->left = helper(lower, val);
        root->right = helper(val, upper);
        return root;

    }

    int idx = 0;
    vector<int> preorder_;
    int n;
};
