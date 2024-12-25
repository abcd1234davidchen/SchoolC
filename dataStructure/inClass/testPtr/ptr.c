#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int a;
    struct Node* left;
    struct Node* right;
} node;

void insert(node** root, int value) {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->a = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (*root == NULL) {
        *root = newNode;
        return;
    }

    node* current = *root;
    node* parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->a) {
            current = current->left;
        } else if (value > current->a) {
            current = current->right;
        } else {
            free(newNode);
            return; // Value already exists in the tree
        }
    }

    if (value < parent->a) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }
}

void printInOrder(node* root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->a);
    printInOrder(root->right);
}

int main() {
    node* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);

    printInOrder(root);
    printf("\n");

    return 0;
}
