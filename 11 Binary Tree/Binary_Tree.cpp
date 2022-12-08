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

class BinaryTree {
    public:
    Node* root;
    BinaryTree() {
        root = NULL;
    }

    void insert(int data);
    //Traversals:
    void levelOrder();
    void preOrder(Node *root);
    void inOrder(Node *root);
    void postOrder(Node *root);
    //Search:
    bool Search(Node *root, int key);
};

void BinaryTree::levelOrder() {
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

void BinaryTree::insert(int data) {
    // If tree is empty, assign new node address to root
    if(root == NULL){
        root = new Node(data);
        return;
    }

    // Else, do level order traversal until we find an empty
    // place, i.e. either left child or right child of some
    // node is pointing to NULL
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp -> left = new Node(data);
            return;
        }

        if(temp -> right != NULL)
            q.push(temp->right);
        else {
            temp -> right = new Node(data);
            return;
        }
    }
}

void BinaryTree::preOrder(Node* root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void BinaryTree::inOrder(Node* root) {
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void BinaryTree::postOrder(Node* root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bool BinaryTree::Search(Node* root, int key){
    if(root == NULL)
        return false;
    if(root->data == key)
        return true;

    bool res1 = Search(root->left, key);
    if(res1) return true;

    return Search(root->right, key);
}

int main()
{
    BinaryTree t;
    t.root = new Node(10);
    t.root->left = new Node(11);
    t.root->left->left = new Node(7);
    t.root->right = new Node(9);
    t.root->right->left = new Node(15);
    t.root->right->right = new Node(8);

    cout << "Level-order traversal before insertion:" << endl;
    t.levelOrder();

    int key = 12;
    t.insert(key);

    cout << "Level-order traversal after insertion:" << endl;
    t.levelOrder();

    cout << "Preorder traversal is: ";
    t.preOrder(t.root);
    cout << endl;

    cout << "Inorder traversal is: ";
    t.inOrder(t.root);
    cout << endl;

    cout << "Postorder traversal is: ";
    t.postOrder(t.root);
    cout << endl;

    if(t.Search(t.root, 11))
        cout << "Yes";
    else
        cout << "NO";

    return 0;
}