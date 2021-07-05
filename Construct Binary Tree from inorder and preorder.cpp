https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
Solution
You need to understand preorder and postorder traversal first, and then go ahead.

Basic idea is:

preorder[0] is the root node of the tree
preorder[x] is a root node of a sub tree
In in-order traversal
When inorder[index] is an item in the in-order traversal
inorder[0]-inorder[index-1] are on the left branch
inorder[index+1]-inorder[size()-1] are on the right branch
if there is nothing on the left, that means the left child of the node is NULL
if there is nothing on the right, that means the right child of the node is NULL
Algorithm:

Start from rootIdx 0
Find preorder[rootIdx] from inorder, let's call the index pivot
Create a new node with inorder[pivot]
Create its left child recursively
Create its right child recursively
Return the created node.
The implementation is self explanatory. Have a look :)

Code
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
};
