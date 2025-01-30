#include <iostream>
using namespace std;

// Node structure for the Red-Black Tree
struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
    bool color; // true = RED, false = BLACK
};

// Class for Red-Black Tree
class RedBlackTree {
private:
    Node *root;
    Node *TNULL;

    // Initialize the TNULL node
    void initializeTNULL() {
        TNULL = new Node;
        TNULL->data = 0;
        TNULL->color = false;
        TNULL->left = nullptr;
        TNULL->right = nullptr;
    }

    // Rotate left
    void leftRotate(Node *x) {
        Node *y = x->right;
        x->right = y->left;
        if (y->left != TNULL) {
            y->left->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->left) {
            x->parent->left = y;
        } else {
            x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
    }

    // Rotate right
    void rightRotate(Node *x) {
        Node *y = x->left;
        x->left = y->right;
        if (y->right != TNULL) {
            y->right->parent = x;
        }
        y->parent = x->parent;
        if (x->parent == nullptr) {
            this->root = y;
        } else if (x == x->parent->right) {
            x->parent->right = y;
        } else {
            x->parent->left = y;
        }
        y->right = x;
        x->parent = y;
    }

    // Fix the Red-Black Tree properties after insertion
    void fixInsert(Node *k) {
        Node *u; // Uncle node
        while (k->parent->color == true) {
            if (k->parent == k->parent->parent->left) {
                u = k->parent->parent->right; // Uncle
                if (u->color == true) {
                    // Case 1: Uncle is red
                    u->color = false;
                    k->parent->color = false;
                    k->parent->parent->color = true;
                    k = k->parent->parent;
                } else {
                    // Case 2 & 3: Uncle is black
                    if (k == k->parent->right) {
                        // Case 2: Rotate left
                        k = k->parent;
                        leftRotate(k);
                    }
                    // Case 3: Rotate right
                    k->parent->color = false;
                    k->parent->parent->color = true;
                    rightRotate(k->parent->parent);
                }
            } else {
                // Mirror cases for the right child
                u = k->parent->parent->left; // Uncle
                if (u->color == true) {
                    // Case 1: Uncle is red
                    u->color = false;
                    k->parent->color = false;
                    k->parent->parent->color = true;
                    k = k->parent->parent;
                } else {
                    // Case 2 & 3: Uncle is black
                    if (k == k->parent->left) {
                        // Case 2: Rotate right
                        k = k->parent;
                        rightRotate(k);
                    }
                    // Case 3: Rotate left
                    k->parent->color = false;
                    k->parent->parent->color = true;
                    leftRotate(k->parent->parent);
                }
            }
            if (k == root) {
                break;
            }
        }
        root->color = false;
    }

    // Helper function to print the tree (inorder traversal)
    void printHelper(Node *root, string indent, bool last) {
        if (root != TNULL) {
            cout << indent;
            if (last) {
                cout << "R----";
                indent += "     ";
            } else {
                cout << "L----";
                indent += "|    ";
            }

            string color = root->color ? "RED" : "BLACK";
            cout << root->data << "(" << color << ")" << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }

public:
    // Constructor
    RedBlackTree() {
        initializeTNULL();
        root = TNULL;
    }

    // Insert a new node
    void insert(int key) {
        Node *node = new Node;
        node->parent = nullptr;
        node->data = key;
        node->left = TNULL;
        node->right = TNULL;
        node->color = true; // New nodes are initially red

        Node *y = nullptr;
        Node *x = this->root;

        while (x != TNULL) {
            y = x;
            if (node->data < x->data) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        // Assign parent to the new node
        node->parent = y;
        if (y == nullptr) {
            root = node;
        } else if (node->data < y->data) {
            y->left = node;
        } else {
            y->right = node;
        }

        // If the new node is the root, set it as black
        if (node->parent == nullptr) {
            node->color = false;
            return;
        }

        // If the grandparent is null, simply return
        if (node->parent->parent == nullptr) {
            return;
        }

        // Fix the tree
        fixInsert(node);
    }

    // Print the tree structure
    void printTree() {
        if (root) {
            printHelper(this->root, "", true);
        }
    }
};

int main() {
    RedBlackTree rbt;

    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);
    rbt.insert(27);

    cout << "Red-Black Tree after insertion:" << endl;
    rbt.printTree();

    return 0;
}
