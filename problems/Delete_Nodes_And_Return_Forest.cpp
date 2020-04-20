/**
 * When we encounter tree problem, we always think of using recursion
 * first or DFS. The key to solve this problem is that we only
 * consider those nodes who are root node and not deleted and we push
 * these nodes to the final result. In DFS, we follow the order
 * current node, then left, then right.
 */



class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (int i = 0; i < to_delete.size(); ++i) {
            st.insert(to_delete[i]);
        }
        dfs(root, st, res, true);
        return res;

    }

private:
    TreeNode* dfs(TreeNode* node, set<int>& st, vector<TreeNode*> & res, bool is_root) {
        if (node == NULL) return NULL;
        bool deleted;
        if (st.find(node->val) != st.end()) {deleted = true;}
        else {deleted = false;}
        if (is_root and !deleted) {res.push_back(node);}
        node->left = dfs(node->left, st, res, deleted);
        node->right = dfs(node->right, st, res, deleted);
        return deleted?NULL:node;
    }
    vector<TreeNode*> res;
    set<int> st;
};
