#include <iostream>
#include "infToPos.h"
using namespace std;


struct Node {
    char data;
    Node *left;
    Node *right;
};


Node* createExpressionTree(char *postfix) {

    stack<struct Node*> s;
    struct Node *n, *l, *r;

    int len = strlen(postfix);
    for (int i=0; i<len; i++) {

        char current = postfix[i];
        n = new Node;
        n->data = current;
        n->left = NULL;
        n->right = NULL;


        if (isOperator(current)!=0) {
            r = s.top();
            s.pop();
            l = s.top();
            s.pop();

            n->right = r;
            n->left = l;
        }

        s.push(n);
    }

    struct Node *ETRoot = s.top();
    s.pop();

    return ETRoot;
}


void traverseInOrder(struct Node *temp) {
    if (temp!=NULL) {
        traverseInOrder(temp->left);
        cout << temp->data;
        traverseInOrder(temp->right);
    }
}


void traversePreOrder(struct Node *temp) {
    if (temp!=NULL) {
        cout << temp->data;
        traversePreOrder(temp->left);
        traversePreOrder(temp->right);
    }
}


void traversePostOrder(struct Node *temp) {
    if (temp!=NULL) {
        traversePostOrder(temp->left);
        traversePostOrder(temp->right);
        cout << temp->data;
    }
}


int main() {

    // char infix[100] = "a+b";
    char infix[100] = "A+B*C/(E-F)*(A^(B-C/D))";
    // inputExpression(infix);
    cout << infix << endl;
    
    char postfix[100];
    infixToPostfix(infix, postfix);
    cout << postfix << "\n\n" << endl;


    struct Node *ETRoot = new Node;
    ETRoot = createExpressionTree(postfix);

    cout << "Pre-Order: ";  traversePreOrder(ETRoot); cout << endl;
    cout << "Post-Order: "; traversePostOrder(ETRoot); cout << endl;
    cout << "In-Order: ";   traverseInOrder(ETRoot); cout << endl;
    
    return 0;
}
