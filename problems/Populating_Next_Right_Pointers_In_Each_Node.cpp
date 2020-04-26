/**
 * This problem can be solved by using Queue, AKA BFS. We need to
 * divide the levels in the queue, as the for loop in the while
 * loop. We point the next pointer of the previous node to the next
 * node in the same level.
 */



class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<Node*> nodes;
            for (int i = 0; i < sz; ++i) {
                auto tmp = q.front();
                q.pop();
                if (i < sz-1) {tmp->next = q.front();}
                if (tmp->left) {
                    q.push(tmp->left);
                    q.push(tmp->right);
                }

            }

        }
        return root;
    }


};
