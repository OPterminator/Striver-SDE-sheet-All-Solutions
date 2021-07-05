// class for Tree node
class Node {
public:
    Node *left, *right;
    int data;
    Node() { left = right = 0; }
    Node(int data)
    {
        left = right = 0;
        this->data = data;
    }
};
 
/*
          1
         / \
        2   3
         \
          4
           \
            5
             \
              6
    Top view of the above binary tree is
    2 1 3 6
*/
 
// class for Tree
class Tree {
public:
    Node* root;
    Tree() { root = 0; }
 
    void topView()
    {
        // queue for holding nodes and their horizontal
        // distance from the root node
        queue<pair<Node*, int> > q;
 
        // pushing root node with distance 0
        q.push(make_pair(root, 0));
 
        // hd is currect node's horizontal distance from
        // root node l is currect left min horizontal
        // distance (or max in magnitude) so far from the
        // root node r is currect right max horizontal
        // distance so far from the root node
 
        int hd = 0, l = 0, r = 0;
 
        // stack is for holding left node's data because
        // they will appear in reverse order that is why
        // using stack
        stack<int> left;
 
        // vector is for holding right node's data
        vector<int> right;
 
        Node* node;
 
        while (q.size()) {
 
            node = q.front().first;
            hd = q.front().second;
 
            if (hd < l) {
                left.push(node->data);
                l = hd;
            }
            else if (hd > r) {
                right.push_back(node->data);
                r = hd;
            }
 
            if (node->left) {
                q.push(make_pair(node->left, hd - 1));
            }
            if (node->right) {
                q.push(make_pair(node->right, hd + 1));
            }
 
            q.pop();
        }
        // printing the left node's data in reverse order
        while (left.size()) {
            cout << left.top() << " ";
            left.pop();
        }
 
        // then printing the root node's data
        cout << root->data << " ";
 
        // finally printing the right node's data
        for (auto x : right) {
            cout << x << " ";
        }
    }
};

