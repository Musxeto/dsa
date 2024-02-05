#include <iostream>
using namespace std;

struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
};

int getHeight(AVLNode* node) {
    return (node == NULL) ? 0 : node->height;
}

int getBalance(AVLNode* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

AVLNode* createNode(int data) {
    AVLNode* newNode = new AVLNode();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

AVLNode* insertNode(AVLNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    } else {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalance(root);

    if (balance > 1 && data < root->left->data) {
        return rightRotate(root);
    }

    if (balance < -1 && data > root->right->data) {
        return leftRotate(root);
    }

    if (balance > 1 && data > root->left->data) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && data < root->right->data) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrderTraversal(AVLNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void displayMenu() {
    cout << "AVL Tree Operations:" << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. In-order Traversal" << endl;
    cout << "3. Exit" << endl;
}

int main() {
    AVLNode* root = NULL;
    int choice, value;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                cout << "In-order traversal of the AVL tree: ";
                inOrderTraversal(root);
                cout << endl;
                break;
            case 3:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}

