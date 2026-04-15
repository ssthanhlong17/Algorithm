/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };sc
 */
int minDepth(struct TreeNode* root) {

    if(root == NULL) return 0;

    if(root->left == NULL) return 1 + minDepth(root->right);

    if(root->right == NULL) return 1 + minDepth(root->left);

    int left = minDepth(root->left) + 1;
    int right = minDepth(root->right) + 1;

    return (left < right) ? left : right;


}