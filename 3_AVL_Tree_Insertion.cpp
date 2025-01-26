#include <iostream>
using namespace std;

// Node structure for the AVL tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

// Function to get the height of a node
int height(Node* node) {
    return node ? node->height : 0;
}

// Function to calculate the balance factor of a node
int getBalanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Function to update the height of a node
void updateHeight(Node* node) {
    if (node) {
        node->height = 1 + max(height(node->left), height(node->right));
    }
}

// Right rotation (LL case)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotation (RR case)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert a key into the AVL tree and return the new root
Node* insert(Node* node, int key) {
    // Step 1: Perform the normal BST insertion
    if (!node) {
        return new Node(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        // Duplicate keys are not allowed in the AVL tree
        return node;
    }

    // Step 2: Update the height of the current node
    updateHeight(node);

    // Step 3: Get the balance factor to check whether this node is unbalanced
    int balance = getBalanceFactor(node);

    // Step 4: Perform rotations to balance the tree

    // Left Left (LL) case
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }

    // Right Right (RR) case
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }

    // Left Right (LR) case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left (RL) case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Return the unchanged node pointer
    return node;
}

// In-order traversal to print the tree
void inOrderTraversal(Node* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->key << " ";
        inOrderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;

    // Insert elements into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Print the in-order traversal of the AVL tree
    cout << "In-order traversal of the AVL tree: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
