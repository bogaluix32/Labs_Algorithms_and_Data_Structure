/*
Laboratorio 10: arboles
Luis Jimenez Bogantes
Valentina Mendez Solano
Jimena Madriz Abarca
Keylin Mendez Cordero
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define YELLOW "\x1b[33m"
#define RESET_COLOR "\x1b[0m"

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

//-----EJERCICIO 1-----

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

//-----EJERCICIO 2-----

void internalNodes(nodeTree * tree){

    if (tree == NULL){

        return;
    }

    if (tree->left != NULL || tree->right != NULL){

        printf("%d ", tree->data);
        
        internalNodes(tree->left);
        internalNodes(tree->right);
    }
}

//-----EJERCICIO 3-----

void printLeafNodes(nodeTree* tree){

    if (!tree){

        return;
    }

    if (!tree->left && !tree->right){

        printf("%d ", tree->data);
        return;
    }

    if (tree->left){

        printLeafNodes(tree->left);
    }

    if (tree->right){

        printLeafNodes(tree->right);
    }
} 

//-----EJERCICIO 4-----

int sizeTree(nodeTree* tree){

    if (tree == NULL){

        return 0;
    }
    else{

        return (sizeTree(tree->left) + 1 + sizeTree(tree->right));
    }
}

//-----EJERCICIO 5-----

int maxHeight(nodeTree* tree){

    if (tree == NULL){

        return -1;
    }
    else{
        
        int leftHeight = maxHeight(tree->left), rightHeight = maxHeight(tree->right);

        if (leftHeight > rightHeight){

            return (leftHeight + 1);
        }
        else{

            return (rightHeight + 1);
        }
    }
}

//-----EJERCICIO 6-----

//Busca la profundidad de la hoja más a la izquierda del arbol
int findDepth(nodeTree *tree){

    int depth = 0;

    while (tree != NULL){

        depth++;
        tree = tree->left;
    }

    return depth;
}

bool perfectTree(nodeTree *tree, int depth, int level){

    if (tree == NULL){

        return true;
    }

    if (tree->left == NULL && tree->right == NULL){

        return (depth == level + 1);
    }

    if (tree->left == NULL || tree->right == NULL){

        return false;
    }

    return perfectTree(tree->left, depth, level + 1) && perfectTree(tree->right, depth, level + 1);
}

bool isPerfectTree(nodeTree *tree){

    int d = findDepth(tree);

    return perfectTree(tree, d, 0);
}

//-----EJERCICIO 7-----

void auxExistRoute(nodeTree *tree, bool * route, int data_A, int data_B){

    if (tree != NULL){

        if (tree->data == data_B){

            *route = true;
        }
        else{

            if (data_A <= data_B){

                auxExistRoute(tree->right, route, data_A, data_B);
            }
            else{

                auxExistRoute(tree->left, route, data_A, data_B);
            }
        }
    }
    else{

        return;
    }
}

void existRoute(nodeTree * tree, bool * route, int data_A, int data_B){

    if (tree == NULL){

        return;
    }
    else{

        if (tree->data == data_A){

            if (data_A <= data_B){

                auxExistRoute(tree->right, route, data_A, data_B);
            }
            else{
                
                auxExistRoute(tree->left, route, data_A, data_B);
            }
        }
        else{

            existRoute(tree->right, route, data_A, data_B);
            existRoute(tree->left, route, data_A, data_B);
        }
    }
}

int main(){

    nodeTree* tree = NULL;

    tree = insert(tree, 50);
    tree = insert(tree, 30);
    tree = insert(tree, 20);
    tree = insert(tree, 40);
    tree = insert(tree, 70);
    tree = insert(tree, 60);
    tree = insert(tree, 80);

    printf(YELLOW "-----Inorder traversal-----\n" RESET_COLOR);
    inorderTraversal(tree);

    printf(YELLOW "\n-----Preorder traversal-----\n" RESET_COLOR);
    preorderTraversal(tree);

    printf(YELLOW "\n-----Postorder traversal-----\n" RESET_COLOR);
    postorderTraversal(tree);

    printf(YELLOW "\n-----Internal Nodes-----\n" RESET_COLOR);
    internalNodes(tree);

    printf(YELLOW "\n-----Leaf Nodes-----\n" RESET_COLOR);
    printLeafNodes(tree);

    printf(YELLOW "\n-----Tree size-----\n" RESET_COLOR);
    printf("%d nodes", sizeTree(tree));

    printf(YELLOW "\n-----Tree height-----\n" RESET_COLOR);
    printf("%d nodes", maxHeight(tree));

    printf(YELLOW "\n-----Is perfect tree-----\n" RESET_COLOR);
    if (isPerfectTree(tree)){
        printf("true");
    }
    else{
        printf("false");
    }

    bool route = false;
    printf(YELLOW "\n-----Route between nodes-----\n" RESET_COLOR);
    existRoute(tree, &route, 30, 20);
    if (route){
        printf("true\n");
    }
    else{
        printf("false\n");
    }

    return 0;
}