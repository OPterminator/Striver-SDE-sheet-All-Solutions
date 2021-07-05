https://www.educative.io/edpresso/how-to-print-the-left-view-of-a-binary-tree
class node { 
public: 
  int data; 
  node *left, *right; 
}; 
  
// A function to create a new node in the tree
node* newNode(int item) 
{ 
  node* temp = new node(); 
  temp->data = item; 
  temp->left = temp->right = NULL; 
  return temp; 
} 
  
// Recursive function to print left view of a binary tree.
// It takes a root, the current level, and 
// the max level so far of the binary tree
void leftViewUtil(node* root, int level, int* max_level) 
{ 
  if (root == NULL) 
    return; 

  // If we are moving to a new level, print the first node(left-most)
  if (*max_level < level) { 
    cout << root->data << "\t"; 
    *max_level = level; 
  } 

  leftViewUtil(root->left, level + 1, max_level); 
  leftViewUtil(root->right, level + 1, max_level); 
} 
  
void leftView(node* root) 
{ 
  int max_level = 0; 
  leftViewUtil(root, 1, &max_level); 
} 
  
