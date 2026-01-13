#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;

Node* createNode(int data){
    //dynamic memory allocation
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int data){
    //base case
    if(root == NULL) return createNode(data);
    //recursive case
    if(data < root->data){
        root->left = insert(root->left, data); //root left points to...
    }
    else if(data > root->data){
        root->right = insert(root->right, data); //root right points to...
    }
    return root;   
}

Node* search (Node* root, int data){
    if(root == NULL || root->data == data) return root;
    if(data < root->data){
        return search(root->left, data);
    }
    return search(root->right, data);
    /*else if(data > root->data){
        return search(root->right, data);
    }*/
}

Node* findMinimum(Node* root){
    if(root->left == NULL) return root;
    return findMinimum(root->left);
}

Node* delete (Node* root, int data){
    if(root == NULL) return root;
    if(data < root->data){
        root->left = delete(root->left, data);
    }else if(data > root->data){
        root->right = delete(root->right, data);
    }else{
        //Case 1: if root does not have any children
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        //Case 2: if root has exactly one child
        else if(root->left == NULL){
            Node* right_child = root->right;
            free(root);
            return right_child;
        }
        else if(root->right == NULL){
            Node* left_child = root->left;
            free(root);
            return left_child;
        }
        //Case 3: if root has two children
        Node* successor = findMinimum(root->right);
        root->data = successor->data;
        root->right = delete(root->right, successor->data);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%d -> ", root->data);
    inorder(root->right);
}

void preorder(Node* root){
    if(root == NULL) return;
    printf("%d -> ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d -> ", root->data);
}

void freeTree(Node* root){
    if(root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(){
    Node* root = NULL;
    root = insert(root, 19);

    insert(root, 7);
    insert(root, 23);
    insert(root, 21);
    insert(root, 25);
    insert(root, 9);
    insert(root, 1);
    insert(root, 3);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");
    delete(root, 23);
    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    freeTree(root);

    return 0;
}