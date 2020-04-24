/**
 * This problem can be solved using DFS bottom up. Bottom up method
 * follows: 1. Check null nodes; 2. check left subtree; 3. check right
 * subtree; 3. return results.
 */



class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) {return 0;}
        is_uni(root);
        return count;


    }

private:
    int count = 0;
    bool is_uni(TreeNode* node) {
        if (node->left == NULL and node->right == NULL) {
            count++;
            return true;
        }
        bool is_u = true;
        if (node->left != NULL) {
            is_u = is_uni(node->left) and is_u and node->val == node->left->val;
        }
        if (node->right != NULL) {
            is_u = is_uni(node->right) and is_u and node->val == node->right->val;
        }
        if (!is_u) {return false;}
        count++;
        return true;
    }

};
