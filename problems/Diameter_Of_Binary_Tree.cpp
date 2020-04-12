/**
 * When asking the longest path we should think of DFS using recursive
 * method. The idea is the diameter of binary tree is the summation
 * between the height of the root on the left and right, diameter =
 * height_L+height_R. The hight of the root is equal to max(L_child, R_child)+1,
 * that is the maximum of the height of left and right child plus 1.
 */



class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return res_;
    }

    int diameter(TreeNode* root) {
        if (root == NULL) {return 0;}
        int L = diameter(root->left);
        int R = diameter(root->right);
        res_ = max(res_, L+R);
        return max(L, R)+1;
    }
private:
    int res_;
};
