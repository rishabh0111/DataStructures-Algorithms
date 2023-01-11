#include <iostream>
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

int findPosition(int in[], int element, int n) {
        for(int i=0; i < n; i++)
            if(in[i] == element)
                return i;
        return -1;
}
    
Node* solve(int in[], int pre[], int &index, int inStart, int inEnd, int n) {
    // Base Case
    if (index >= n || inStart > inEnd)
        return NULL;

    // create a root node for element
    int element = pre[index++];
    Node* root = new Node(element);

    // find element's index in inorder
    int position = findPosition(in,element,n);

    root->left = solve(in, pre, index, inStart, position-1, n);
    root->right = solve(in, pre, index, position + 1, inEnd, n);

    return root;
}

Node* buildTree (int in[], int pre[], int n) {
    int preIndex = 0;
    Node* ans = solve(in, pre, preIndex, 0, n-1, n);
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