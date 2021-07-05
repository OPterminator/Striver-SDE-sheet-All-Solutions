https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

Recursive
void flatten(TreeNode* root) {
    if (!root) return;
    flatten(root->left);
    flatten(root->right);
    TreeNode *tmp = root->right;
    root->right = root->left;
    root->left = nullptr;
    while (root->right)
        root = root->right;
    root->right = tmp;
}

Iterative
void flatten(TreeNode *root) {
	while (root) {
		if (root->left && root->right) {
			TreeNode* t = root->left;
			while (t->right)
				t = t->right;
			t->right = root->right;
		}

        if(root->left)
		    root->right = root->left;
		root->left = NULL;
		root = root->right;
	}
}
