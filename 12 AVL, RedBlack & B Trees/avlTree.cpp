#include<iostream>
using namespace std;

// An AVL tree node
class Node {
	public:
	int data;
	Node *left;
	Node *right;
	int height;

    Node(int key) {
        this->data = key;
        this->left = this->right = NULL;
        height = 1;
    }
};

// height of the tree
int height(Node *N) {
	if (N == NULL)
		return 0;
	return N->height;
}

// right rotate subtree rooted with y
Node* rightRotate(Node *y) {
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left), height(y->right)) + 1;
	x->height = max(height(x->left), height(x->right)) + 1;

	// Return new root
	return x;
}

// left rotate subtree rooted with x
Node* leftRotate(Node *x) {
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left), height(x->right)) + 1;
	y->height = max(height(y->left), height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
    return height(N->left) - height(N->right);
}

// Inserting
Node* insert(Node* node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(new Node(key));

	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),
						height(node->right));

	/* 3. Get the balance factor of this ancestor
		node to check whether this node became
		unbalanced */
	int balance = getBalance(node);

	// If this node becomes unbalanced, then
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->data)
		return rightRotate(node);

	// Right Right Case
	if (balance < -1 && key > node->right->data)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->data)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->data)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
/*
Time Complexity: O(n*log(n)), For Insertion
Auxiliary Space: O(1)
*/

/* Given a non-empty binary search tree,
return the node with minimum key value
found in that tree. Note that the entire
tree does not need to be searched. */
Node* minValueNode(Node* node) {
    Node* current = node;

    while(current->left != NULL)
        current = current->left;

    return current;
}

// Deletion
Node* remove(Node* root, int key) {
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
    
    if (key < root->data)
        root->left = remove(root->left, key);
    else if ( key > root->data)
        root->right = remove(root->right, key);
    else {
        // node wiht only one child or no child
        if((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            //No child
            if(temp == NULL) {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp;
            free(temp);
        }
        else {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }

    // If the tree had only one node
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left), height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 &&
        getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 &&
        getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 &&
        getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 &&
        getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
/*
Time Complexity: O(n*log(n)), For Insertion
Auxiliary Space: O(1)
*/


void preOrder(Node *root) {
	if(root != NULL) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main() {
	Node *root = NULL;
	
	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);
	
	cout << "Preorder: ";
    preOrder(root);
    cout << endl;
	
    root = remove(root, 10);
    cout << "Preorder traversal after deletion of 10: ";
    preOrder(root);
    cout << endl;

	return 0;
}