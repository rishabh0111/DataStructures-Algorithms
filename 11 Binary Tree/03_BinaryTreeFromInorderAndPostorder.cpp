#include <iostream>
#include <map>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

class BinaryTree {
    public:
    Node* root;
    BinaryTree() {
        root = NULL;
    }
};

void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
    for(int i=0; i < n; i++)
        nodeToIndex[in[i]] = i;
}
    
Node* solve(int in[], int post[], int &index, int inStart, int inEnd, int n, map<int,int> &nodeToIndex) {
    // Base Case
    if (index < 0 || inStart > inEnd)
        return NULL;

    // create a root node for element    
    int element = post[index--];
    Node* root = new Node(element);

    // find element's index in inorder
    int position = nodeToIndex[element];
    
    //in case of PostOrder and Inorder, first build the right subtree
    root->right = solve(in, post, index, position + 1, inEnd, n, nodeToIndex);
    root->left = solve(in, post, index, inStart, position-1, n, nodeToIndex);

    return root;
}

Node* buildTree (int in[], int post[], int n) {
    int postIndex = n-1;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node* ans = solve(in, post, postIndex, 0, n-1, n, nodeToIndex);
    return ans;
}

void preOrder(Node* root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int len = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(in, post, len);
    preOrder(root);
    cout << endl;

    return 0;
}