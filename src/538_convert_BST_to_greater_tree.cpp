class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        _sum = 0;
        traverse(root);
        return root;
    }
private:
    int _sum;
    void traverse(TreeNode* root) {
        if (!root)  return;
        traverse(root->right);
        _sum += root->val;
        root->val = _sum;
        traverse(root->left);
    }
};