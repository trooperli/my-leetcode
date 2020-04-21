/**
 * Two solutions are provided, recursion and iteration. Please pay
 * attention to the iterative solution, which is different from
 * pre-order and post-order.
 */


// Recursive
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
        res.push_back(node->val);
        if (node->right) {
            helper(node->right, res);
        }
    }
};

// Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        stack<TreeNode*> s;
        auto current = root;
        while (current != NULL or !s.empty()) {
            while (current != NULL) {
                s.push(current);
                current = current->left;
            }
            auto tmp = s.top();
            res.push_back(tmp->val);
            s.pop();
            current = tmp->right;

        }
        return res;

    }
};
