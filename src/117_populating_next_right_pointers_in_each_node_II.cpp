/*
* Author: joannechen1223
* Date: 2020.12.08
*/


class Solution {
public:
    Node* connect(Node* root) {
        _connectNext(root);
        return root;
    }

private:
    void _connectNext(Node* root) {
        if (!root)  return;
        if (root->left) {
            if (root->left->next)   return;
            if (root->right)    root->left->next = root->right;
            else    root->left->next = _findNext(root);
        }
        if (root->right) {
            if (root->right->next)  return;
            root->right->next = _findNext(root);
        }
        _connectNext(root->next);
        _connectNext(root->left);
        _connectNext(root->right);
    }
    
    Node* _findNext(Node* root) {
        if(!root)     return NULL;
        Node* nxt = root->next;
        while (nxt) {
            if (nxt->left) return nxt->left;
            if (nxt->right)  return nxt->right;
            nxt = nxt->next;
        }
        return NULL;
    }
};