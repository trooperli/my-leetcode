/**
 * Two solution is provided. The iterative solution is similar to the
 * pre-order one. The sequence of post order is left, right,
 * parent. What we did in the iterative solution is parent, right,
 * left. That's the reason why we need to do a reverse in the end.
 */



// recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode* node, vector<int> & res) {
        if (node == NULL) return;
        if (node->left) {
            helper(node->left, res);
        }
        if (node->right) {
            helper(node->right, res);
        }
        res.push_back(node->val);
    }
};

// Iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto tmp = s.top();
            res.push_back(tmp->val);
            s.pop();
            if (tmp->left) {s.push(tmp->left);}
            if (tmp->right) {s.push(tmp->right);}
        }
        reverse(res.begin(), res.end());
        return res;

    }
};
