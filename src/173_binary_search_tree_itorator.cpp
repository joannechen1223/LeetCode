/*
* Author: joannechen1223
* Date: 2020.12.20
* Note: Using stack instead of array to store value in order to meet the requestment of space complexity in O(h).
*/


class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        _s.push(root);
        pushAllLeft(root);
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* n = _s.top();
        _s.pop();
        if (n->right) {
            _s.push(n->right);
            pushAllLeft(n->right);
        }
        return n->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !_s.empty();
    }
private:
    stack<TreeNode*> _s;
    
    void pushAllLeft(TreeNode* root) {
        TreeNode* current = root->left;
        while (current) {
            _s.push(current);
            current = current->left;
        }
    }
};