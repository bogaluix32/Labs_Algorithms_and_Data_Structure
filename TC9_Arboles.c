/* Trabajo de clase 9: Arboles
    Estudiantes:
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keylin Mendez Cordero */

#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    int data;
    struct tree *left;
    struct tree *right;
}nodeTree;

nodeTree* createNode(int newData){
    
    nodeTree* newNode = (nodeTree*) malloc(sizeof(nodeTree));

    newNode->data = newData;
    newNode->left = newNode->right = NULL;

    return newNode;
}

nodeTree* insert(nodeTree* tree, int newData){

    if (tree == NULL){
        return createNode(newData);
    }

    if (newData < tree->data){
        tree->left = insert(tree->left, newData);
    }
    else if(newData > tree->data){
        tree->right = insert(tree->right, newData);
    }

    return tree;
}

void inorderTraversal(nodeTree* tree){
    
    if (tree == NULL){
        return;
    }

    inorderTraversal(tree->left);
    printf("%d ", tree->data);
    inorderTraversal(tree->right);
}

void preorderTraversal(nodeTree* tree){

    if (tree == NULL){
        return;
    }

    printf("%d ", tree->data);

    preorderTraversal(tree->left);
    preorderTraversal(tree->right);
}

void postorderTraversal(nodeTree* tree){

    if (tree == NULL){
        return;
    }

    postorderTraversal(tree->left);
    postorderTraversal(tree->right);

    printf("%d ", tree->data);
}

nodeTree* delete(nodeTree* tree, int dataToDelete){

    if (tree == NULL){
        return tree;
    }

    if (tree->data > dataToDelete){
        tree->left = delete(tree->left, dataToDelete);
        return tree;
    }
    else if (tree->data < dataToDelete){
        tree->right = delete(tree->right, dataToDelete);
        return tree;
    }

    if (tree->left == NULL){
        nodeTree* current = tree->right;
        free(tree);
        return current;
    }
    else if (tree->right == NULL){
        nodeTree* current = tree->left;
        free(tree);
        return current;
    }
    else{
        nodeTree* successorParent = tree;
        nodeTree* successor = tree->right;

        while (successor->left != NULL){
            successorParent = successor;
            successor = successor->left;
        }

        if (successorParent != tree){
            successorParent->left = successor->right;
        }
        else{
            successorParent->right = successor->right;
        }

        tree->data = successor->data;

        free(successor);
        return tree;
    }
}

nodeTree* search(nodeTree* tree, int dataToSearch){

    nodeTree *aux = tree;

    if (aux != NULL){
        
        if (dataToSearch < aux->data){
            search(aux->left, dataToSearch);
        }
        else if (dataToSearch > aux->data){
            search(aux->right, dataToSearch);
        }
        else{
            return aux;
        }
    }
    else{
        return NULL;
    }
}

int main(){

    nodeTree* tree = NULL;
    nodeTree* searchResult;

    tree = insert(tree, 50);
    tree = insert(tree, 30);
    tree = insert(tree, 20);
    tree = insert(tree, 40);
    tree = insert(tree, 70);
    tree = insert(tree, 60);
    tree = insert(tree, 80);

    printf("-----Inorder traversal-----\n");
    inorderTraversal(tree);

    printf("\n-----Preorder traversal-----\n");
    preorderTraversal(tree);

    printf("\n-----Postorder traversal-----\n");
    postorderTraversal(tree);

    printf("\n-----Search 40-----\n");
    searchResult = search(tree, 40);
    if (searchResult != NULL){
        printf("Data %d found", searchResult->data);
    }
    else{
        printf("Data not found");
    }

    printf("\n-----Search 90-----\n");
    searchResult = search(tree, 90);
    if (searchResult != NULL){
        printf("Data %d found", searchResult->data);
    }
    else{
        printf("Data not found");
    }
    
    printf("\n-----Delete 20-----\n");
    tree = delete(tree, 20);
    printf("New tree:\n");
    inorderTraversal(tree);

    printf("\n-----Delete 30-----\n");
    tree = delete(tree, 30);
    printf("New tree:\n");
    inorderTraversal(tree);

    printf("\n-----Delete 50-----\n");
    tree = delete(tree, 50);
    printf("New tree:\n");
    inorderTraversal(tree);
    
    return 0;
}