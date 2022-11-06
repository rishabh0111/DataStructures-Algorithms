#include<bits/stdc++.h>
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

    void levelOrderTraversal();
    Node* insert(int data);
};

void BinaryTree::levelOrderTraversal() {
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

Node* BinaryTree::insert(int data) {
    // If tree is empty, assign new node address to root
    if(root == NULL){
        root = new Node(data);
        return root;
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
            return root;
        }

        if(temp -> right != NULL)
            q.push(temp->right);
        else {
            temp -> right = new Node(data);
            return root;
        }
    }
    return NULL;
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
    t.levelOrderTraversal();

    int key = 12;
    t.root = t.insert(key);

    cout << "Level-order traversal after insertion:" << endl;
    t.levelOrderTraversal();

    return 0;
}