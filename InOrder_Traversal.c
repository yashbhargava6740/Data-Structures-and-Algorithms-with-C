#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};
typedef struct Node Node;

Node* createNode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    if(n == NULL) 
        return NULL;
    n -> data = val;
    n -> left = NULL;
    n -> right = NULL;
    return n;
}

void inOrderTraverse(Node *ptr) {
    if(ptr != NULL) {
        inOrderTraverse(ptr -> left);
        printf("%d ", ptr -> data);
        inOrderTraverse(ptr -> right);
        
    }
}

void main() {
    Node *root = createNode(10);
    Node *c1 = createNode(20);
    Node *c2 = createNode(30);
    Node *c1c1 = createNode(40);
    Node *c1c2 = createNode(50);
    Node *c2c1 = createNode(60);
    Node *c2c2 = createNode(70);
    root -> left = c1;
    root -> right = c2;
    c1 -> left = c1c1;
    c1 -> right = c1c2;
    c2 -> left = c2c1;
    c2 -> right = c2c2;
    inOrderTraverse(root);
}