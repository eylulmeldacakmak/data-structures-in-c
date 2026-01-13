#include <stdio.h>
#include <stdlib.h>

struct BinaryNode{
    int data;
    struct BinaryNode* left, *right;
};

struct BinaryNode* newNode(int data){
    //dynamic memory allocation
    struct BinaryNode* node = (struct BinaryNode*)malloc(sizeof(struct BinaryNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct BinaryNode* insertLeft(struct BinaryNode* root, int item){
    root->left = newNode(item);
    return root->left;
}

struct BinaryNode* insertRight(struct BinaryNode* root, int item){
    root->right = newNode(item);
    return root->right;
}

/*tree traversals use recursion*/
void inorderTraversal(struct BinaryNode* root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    printf("%d -> ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct BinaryNode* root){
    if(root == NULL) return;
    printf("%d -> ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct BinaryNode* root){
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d -> ", root->data);
}

void freeTree(struct BinaryNode* root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    struct BinaryNode* root = newNode(1);
    insertLeft(root, 2);
    insertRight(root, 3);
    insertLeft(root->left, 4);
    insertRight(root->left, 5);

    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\nPreorder traversal: ");
    preorderTraversal(root);
    printf("\nPostorder traversal: ");
    postorderTraversal(root);

    freeTree(root);

    return 0;
}