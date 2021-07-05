
// A tree node
struct Tree
{
	int data;
	Tree *left;
	Tree *right;
  Tree(int data) 
    { 
        this -> data = data; 
        left = NULL;
        right = NULL; 
    }     
};
void bottomview(Tree * root, map<int,vector<int>>& m, int lev, int h_dist){
  // Base case
  if (root == NULL)
    return;
   // if the node is the first one with a specific horizontal
   // distance, save its details.
  if (m.find(h_dist) == m.end()) {   
    m[h_dist].push_back(lev);
    m[h_dist].push_back(root -> data);
  }
  // Else, save the details if this node only if this node
  // is at a greater level than the already saved node
  else {
    if (m[h_dist][0] <= lev) {
      m[h_dist][0] = lev;
      m[h_dist][1]= root -> data;
    }
  }
  // Calling the function for the right and left subtrees
  // with the appropriate parameters.
  bottomview(root -> left, m, lev + 1, h_dist - 1);
  bottomview(root -> right, m, lev + 1, h_dist + 1);
}
