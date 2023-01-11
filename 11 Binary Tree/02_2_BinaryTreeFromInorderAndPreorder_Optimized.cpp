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
    
Node* solve(int in[], int pre[], int &index, int inStart, int inEnd, int n, map<int,int> &nodeToIndex) {
    // Base Case
    if (index >= n || inStart > inEnd)
        return NULL;

    // create a root node for element    
    int element = pre[index++];
    Node* root = new Node(element);

    // find element's index in inorder
    int position = nodeToIndex[element];

    root->left = solve(in, pre, index, inStart, position-1, n, nodeToIndex);
    root->right = solve(in, pre, index, position + 1, inEnd, n, nodeToIndex);

    return root;
}

Node* buildTree (int in[], int pre[], int n) {
    int preIndex = 0;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node* ans = solve(in, pre, preIndex, 0, n-1, n, nodeToIndex);
    return ans;
}

void postOrder(Node* root) {
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main() {
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int len = sizeof(in) / sizeof(in[0]);
    Node* root = buildTree(in, pre, len);
    postOrder(root);
    cout << endl;

    return 0;
}