https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

 check the target value during the search, which makes the solution conciser.


Complexity
O(N) Time O(N) Space

C++

    unordered_set<int> s;
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (s.count(k - root->val)) return true;
        s.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
