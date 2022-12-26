#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};


Node* newNode(int item) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Inorder Traversal
void descending(Node *root) {
  if (root != NULL) {
    descending(root->right);
    cout << root->key << " -> ";
    descending(root->left);
  }
}

void inorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    cout << root->key << " -> ";
    inorder(root->right);
  }
}

// Preorder Traversal
void preorder(Node *root) {
  if (root != NULL) {
    cout << root->key << " -> ";
    inorder(root->left);
    inorder(root->right);
  }
}

// Postorder Traversal
void postorder(Node *root) {
  if (root != NULL) {
    inorder(root->left);
    inorder(root->right);
    cout << root->key << " -> ";
  }
}


Node* insert(Node *Node, int value) {

    if (Node==NULL) return newNode(value);

    if (value < Node->key)
        Node->left = insert(Node->left, value);
    else
        Node->right = insert(Node->right, value);

    return Node;
}


Node* minValueNode(Node *HeadNode) {
    Node *current = HeadNode;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

int min(Node *hn) {
    if (hn->left == NULL)
        return hn->key;

    return min(hn->left);
}

Node* maxValueNode(Node *HeadNode) {
    Node *current = HeadNode;

    while (current && current->right != NULL)
        current = current->right;

    return current;
}

Node* deleteNode(Node *root, int key) {
    // Return if the tree is empty
    if (root == NULL) return root;

    // Find the Node to be deleted
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }

    else {  // key == root->key
        // If the Node is with only one child or no child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root);
            return temp;
        } 
        
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // If the Node has two children
        struct Node *temp = minValueNode(root->right);

        // Place the inorder successor in position of the Node to be deleted
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Driver code
int main() {
    struct Node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    // cout << "Preorder traversal: ";
    // preorder(root);
    // cout << endl;

    cout << "Inorder traversal: ";
    descending(root);
    cout << endl;

    // cout << "Postorder traversal: ";
    // postorder(root);
    // cout << endl;

    // root = deleteNode(root, 3);
    // cout << endl << "After deleting 3" << endl;
    // cout << "Inorder traversal: ";
    // inorder(root);
    // cout << endl;

    return 1;
}
