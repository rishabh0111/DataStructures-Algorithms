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

// Time Complexity: Best: O(1) Average: O(logN) Worst: O(N)
bool BST::search(Node* root, int key) {
    if(root == NULL)
        return false;
    if(root->data == key)
        return true;
    if(root->data > key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    BST t;

    cout << "Enter data to create BST" << endl;
    t.takeInput();
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
    
    cout << t.search(t.root,27) << endl;
    cout << t.search(t.root,20) << endl;

    return 0;
}