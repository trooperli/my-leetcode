/**
 * This problem can be solved by recursion. We need to pay attention
 * to the return value in calSum function, which is node->val+max(l,
 * r). The reason that it is from parent to the subtree, it can go
 * either left or right, but not both.
 */



class Solution {
public:
    int maxPathSum(TreeNode* root) {
        calSum(root);
        return res_;


    }
private:
    int res_ = INT_MIN;
    int calSum(TreeNode* node) {
        if (node == NULL) {return 0;}
        int l = max(calSum(node->left), 0);
        int r = max(calSum(node->right), 0);
        int sum = node->val+l+r;
        res_ = max(res_, sum);
        return node->val+max(l, r);

    }
};
