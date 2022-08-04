#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};
typedef struct Node Node;

Node *createNode(int data) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp -> data = data;             
    temp -> right = NULL;
    temp -> left = NULL;
    return temp;
}

Node *insertNode(Node *root, int data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(root -> data > data) {
        root -> left = insertNode(root -> left, data);
    }
    else if(root -> data < data) {
        root -> right = insertNode(root -> right, data);
    }
    return root;
}

int isBst(Node *root) {
    static Node *prev = NULL;
    if(root) {
        if(!isBst(root -> left)) 
            return 0;
        if(prev != NULL && root -> data <= prev -> data) {
            return 0;
        }
        prev = root;
        return isBst(root -> right);
    }
    return 1;
    
}

void traverse(Node *root) {
    if(root == NULL)
        return;
    traverse(root -> left);
    printf("%d -> ", root -> data);
    traverse(root -> right);
}

int searchEle(Node *root, int key) {
    if(root) {
        if(root -> data == key) {
            return 1;
        }
        if(root -> data < key) {
            searchEle(root -> right, key);
        }
        if(root -> data > key) {
            searchEle(root -> left, key);
        }
    }
}
Node *inOrderSucc(Node *root) {
    while(root -> left != NULL ) {
        root = root -> left;
    }
    return root;
}
Node *deleteNode(Node *root, int key) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> data > key) {
        root -> left = deleteNode(root -> left, key);
    }
    else if(root -> data < key) {
        root -> right = deleteNode(root -> right, key);
    }
    else {
        if(root -> left == NULL) 
            return root -> right;
        else if(root -> right == NULL) 
            return root -> left;
        else {
            Node *IS = inOrderSucc(root -> right);
            root -> data = IS -> data;
            root -> right = deleteNode(root -> right, IS -> data);
        }
    }
    return root;
}
void main() {
    int arr[] = {1,5};
    Node *root = NULL;
    int key;
    key = 1;                       // Change Key Here
    for(int i = 0; i < 2; i++) 
        root = insertNode(root, arr[i]);
    if(isBst(root)) {
        traverse(root);
        printf("NULL");
    } else {
        printf("This is not a Binary Search Tree");
    }
    printf("\n");
    if(searchEle(root, key)) {
        printf("Element Found : - %d", key);
    } else {
        printf("Element Not Found");
    }
    printf("\n");
    root = deleteNode(root, key);
    traverse(root);
    printf("NULL\n");
}