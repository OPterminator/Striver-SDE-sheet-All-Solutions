https://leetcode.com/problems/binary-tree-maximum-path-sum/
class Solution {
    int maxToRoot(TreeNode *root, int &re) {
        if (!root) return 0;
        int l = maxToRoot(root->left, re);
        int r = maxToRoot(root->right, re);
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        if (l + r + root->val > re) re = l + r + root->val;
        return root->val += max(l, r);
    }
public:
    int maxPathSum(TreeNode *root) {
        int max = -2147483648;
        maxToRoot(root, max);
        return max;
    }
};
update the val of each node of the tree bottom-up, the new val 
of TreeNode *x stands for the max sum started from any node in subtree x and ended in x, mataining the re for result in traversal at the same time.
