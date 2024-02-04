#include <iostream>
#include <queue>

using namespace std;

class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode() {
        value = 0;
        left = NULL;
        right = NULL;
    }

    TreeNode(int v) {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    TreeNode* root;

    BST() {
        root = NULL;
    }

    bool isTreeEmpty() {
        return root == NULL;
    }

    void printPreorder(TreeNode* r) {
        if (r == NULL)
            return;

        cout << r->value << " ";
        printPreorder(r->left);
        printPreorder(r->right);
    }

    void printPostorder(TreeNode* r) {
        if (r == NULL)
            return;

        printPostorder(r->left);
        printPostorder(r->right);
        cout << r->value << " ";
    }

    void printInorder(TreeNode* r) {
        if (r == NULL)
            return;

        printInorder(r->left);
        cout << r->value << " ";
        printInorder(r->right);
    }

    void printLevelOrderBFS(TreeNode* r) {
        int h = height(r);
        for (int i = 0; i <= h; i++) {
            printGivenLevel(r, i);
        }
    }

    void printGivenLevel(TreeNode* r, int level) {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->value << " ";
        else {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }

    void printBFS(TreeNode* root) {
        if (root == NULL)
            return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            cout << current->value << " ";

            if (current->left != NULL) {
                q.push(current->left);
            }

            if (current->right != NULL) {
                q.push(current->right);
            }
        }
    }

    void insertIteratively(TreeNode* newNode) {
        TreeNode* temp = root;
        if (root == NULL) {
            root = newNode;
            cout << "Node Inserted as Root" << endl;
            return;
        } else {
            while (temp != NULL) {
                if (temp->value == newNode->value) {
                    cout << "VALUE ALREADY EXISTS, DUPLICATES NOT ALLOWED!" << endl;
                    return;
                } else if (newNode->value < temp->value) {
                    if (temp->left == NULL) {
                        cout << "Value Inserted to Left!" << endl;
                        temp->left = newNode;
                        break;
                    } else {
                        temp = temp->left;
                    }
                } else {
                    if (temp->right == NULL) {
                        cout << "Value Inserted to Right!" << endl;
                        temp->right = newNode;
                        break;
                    } else {
                        temp = temp->right;
                    }
                }
            }
        }
    }

    TreeNode* insertRecursively(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        } else if (val < root->value) {
            root->left = insertRecursively(root->left, val);
        } else if (val > root->value) {
            root->right = insertRecursively(root->right, val);
        }
        return root;
    }

    TreeNode* iterativeSearch(int v) {
        if (root == NULL)
            return root;
        else {
            TreeNode* temp = root;
            while (temp != NULL) {
                if (v == temp->value) {
                    return temp;
                } else if (v < temp->value) {
                    temp = temp->left;
                } else if (v > temp->value) {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode* recursiveSearch(TreeNode* r, int val) {
        if (r == NULL || r->value == val) {
            return r;
        } else if (val < r->value) {
            return recursiveSearch(r->left, val);
        } else if (val > r->value) {
            return recursiveSearch(r->right, val);
        }
    }

    int height(TreeNode* r) {
        if (r == NULL)
            return -1;
        else {
            int lheight = height(r->left);
            int rheight = height(r->right);

            if (lheight > rheight)
                return lheight + 1;
            else
                return rheight + 1;
        }
    }

    TreeNode* minValue(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        return temp;
    }

    TreeNode* maxValue(TreeNode* root) {
        TreeNode* temp = root;
        while (temp->right != NULL) {
            temp = temp->right;
        }
        return temp;
    }

    TreeNode* deleteNode(TreeNode* root, int value) {
        if (root == NULL) {
            return NULL;
        } else if (value < root->value) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        } else {
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            } else {
                TreeNode* temp = minValue(root->right);
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->value);
            }
        }
        return root;
    }

    void deleteTree(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    BST bst;

    int choice;
    int value;
    TreeNode* newNode;

    do {
        cout << "\n------------ Binary Search Tree Operations ------------\n";
        cout << "1. Insert Iteratively\n";
        cout << "2. Insert Recursively\n";
        cout << "3. Delete Node\n";
        cout << "4. Search Iteratively\n";
        cout << "5. Search Recursively\n";
        cout << "6. Print Inorder Traversal\n";
        cout << "7. Print BFS Traversal\n";
        cout << "8. Print Level Order BFS\n";
        cout << "9. Print Preorder Traversal\n";
        cout << "10. Print Postorder Traversal\n";
        cout << "11. Delete Entire Tree\n";
        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                newNode = new TreeNode();
                cout << "Enter the value to insert: ";
                cin >> newNode->value;
                bst.insertIteratively(newNode);
                break;

            case 2:
                cout << "Enter the value to insert recursively: ";
                cin >> value;
                bst.root = bst.insertRecursively(bst.root, value);
                break;

            case 3:
                cout << "Enter the value to delete: ";
                cin >> value;
                bst.deleteNode(bst.root, value);
                break;

            case 4:
                cout << "Enter the value to search iteratively: ";
                cin >> value;
                if (bst.iterativeSearch(value) != NULL)
                    cout << "Value found!\n";
                else
                    cout << "Value not found!\n";
                break;

            case 5:
                cout << "Enter the value to search recursively: ";
                cin >> value;
                if (bst.recursiveSearch(bst.root, value) != NULL)
                    cout << "Value found!\n";
                else
                    cout << "Value not found!\n";
                break;

            case 6:
                cout << "Inorder Traversal: ";
                bst.printInorder(bst.root);
                cout << endl;
                break;

            case 7:
                cout << "BFS Traversal: ";
                bst.printBFS(bst.root);
                cout << endl;
                break;

            case 8:
                cout << "Level Order BFS: ";
                bst.printLevelOrderBFS(bst.root);
                cout << endl;
                break;

            case 9:
                cout << "Preorder Traversal: ";
                bst.printPreorder(bst.root);
                cout << endl;
                break;

            case 10:
                cout << "Postorder Traversal: ";
                bst.printPostorder(bst.root);
                cout << endl;
                break;

            case 11:
                bst.deleteTree(bst.root);
                cout << "Entire Tree Deleted!\n";
                break;

            case 12:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Choice. Please enter a valid option.\n";
        }

    } while (choice != 12);

    return 0;
}
