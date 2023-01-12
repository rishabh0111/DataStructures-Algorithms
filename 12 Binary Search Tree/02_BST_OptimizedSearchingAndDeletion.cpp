#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
    this -> data = d;
    this -> left = this -> right = NULL;
    }
};

class BST {
    public:
    Node* root;
    BST() {
        root = NULL;
    }

    Node* insert(Node* root, int d);
    void takeInput();
    void levelOrder();
    void preOrder(Node* root);
    void inOrder(Node* root);
    void postOrder(Node* root);
    bool search(Node* root, int key);
    Node* minVal(Node* root);
    Node* maxVal(Node* root);
    Node* remove(Node* root, int val);
};

// Time Comlexity: O(logN)
Node* BST::insert(Node* root, int d) {
    // base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }
    if (d > root->data)
        root->right = insert(root->right, d);
    else
        root->left = insert(root->left, d);
    return root;
    
}

void BST::takeInput() {
  int data;
  cin >> data;

  while(data != -1) {
    root = insert(root, data);
    cin >> data;
  }
}

void BST::levelOrder() {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        //when last level completes
        if(temp == NULL) {
            //queue still has some child nodes
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else {
            cout << temp -> data << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void BST::preOrder(Node* root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder of BST is sorted
void BST::inOrder(Node* root) {
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void BST::postOrder(Node* root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

//Searching // Iterative
bool BST::search(Node* root, int key) {
    Node* temp = root;
    while(temp != NULL){
        if(temp->data == key)
            return true;
        if(temp->data > key)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}
// Time Complexity: Best: O(1) Average: O(logN) Worst: O(N)
// Space complexity: O(1), no recursion stack of size h

Node* BST::minVal(Node* root) {
    Node* temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

Node* BST::maxVal(Node* root) {
    Node* temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

/* Previous Approach can be optimized for two children case : 
We can avoid recursive calls by keeping track of the parent node of the successor, 
so that we can simply remove the successor by making the child of a parent NULL.
We know that the successor would always be a leaf node. */
Node* BST::remove(Node* root, int val) {
    // base case
    if(root == NULL)
        return root;
    else if(root->data == val) {
        // no child: 
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        // 1 child:
        //left child
        else if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        else if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // 2 child:
        else if(root->left != NULL && root->right != NULL) {
        Node* succParent = root;
 
        // Find successor
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
 
        // Copy Successor Data to root
        root->data = succ->data;
 
        // Delete Successor and return root
        delete succ;
        return root;
        }
    }
    else if(root->data > val) { // move left
        root->left = remove(root->left, val);
        return root;
    }
    else { // move right
        root->right = remove(root->right, val);
        return root;
    }
    return NULL;
}
// Time Complexity: O(h) ,where h is the height of the BST. 
// Auxiliary Space: O(1).


int main() {
    BST t;

    cout << "Enter data to create BST:" << endl;
    t.takeInput();

    cout << "Level Order: " << endl;
    t.levelOrder();
    
    cout << "Preorder: ";
    t.preOrder(t.root);
    cout << endl;

    cout << "Inorder: ";
    t.inOrder(t.root);
    cout << endl;

    cout << "Postorder: ";
    t.postOrder(t.root);
    cout << endl;
    
    (t.search(t.root,27)) ? cout << "27 is present" << endl : cout << "27 is not present" << endl;
    (t.search(t.root,20)) ? cout << "20 is present" << endl : cout << "20 is not present" << endl;

    cout << "Min value is " << t.minVal(t.root)->data << endl;
    cout << "Max value is " << t.maxVal(t.root)->data << endl;

    // Deleting Node
    // t.root = t.remove(t.root, 30); // with no child
    // t.root = t.remove(t.root, 90); // with 1 child
    t.root = t.remove(t.root, 50); // with 2 child

    // After deletion
    cout << "After Deletion:" << endl;
    cout << "Level Order: " << endl;
    t.levelOrder();
    
    cout << "Preorder: ";
    t.preOrder(t.root);
    cout << endl;

    cout << "Inorder: ";
    t.inOrder(t.root);
    cout << endl;

    cout << "Postorder: ";
    t.postOrder(t.root);
    cout << endl;

    return 0;
}