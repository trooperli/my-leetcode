/**
 * This problem is similar to the post order one. The inorder vector
 * is just to tell which numbers belong to the left subtree and right
 * subtree. The root node starts from the left in the preorder vector.
 */



class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        root_idx = 0;
        int n = inorder.size();
        preorder_ = preorder;
        for (int i = 0; i < n; ++i) {
            mp[inorder[i]] = i;
        }
        return helper(0, n-1);

    }
private:
    int root_idx; // in preorder
    unordered_map<int, int> mp; //key:value in inorder, val: its index
    vector<int> preorder_;
    TreeNode* helper(int left, int right) {
        if (left > right) {return NULL;}
        TreeNode* node = new TreeNode(preorder_[root_idx]);
        int idx = mp[preorder_[root_idx]];
        root_idx++;
        node->left = helper(left, idx-1);
        node->right = helper(idx+1, right);
        return node;
    }

};
