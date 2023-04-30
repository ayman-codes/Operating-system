// Read README file from github.com for full documentation
// https://github.com/ayman-codes/Operating-system/tree/master/hw2

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

// Define a node structure for the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Define a BinaryTree structure that contains a pointer to the root node
struct BinaryTree {
    struct Node* root;
};

// Traverse the binary tree in-order and print each node's data
void trav_order(struct Node* node) {
    if (node != NULL) {
        trav_order(node->left);
        printf("%d ", node->data);
        trav_order(node->right);
    }
}

// Insert a new node with the given data into the binary tree
void insert_node(struct BinaryTree* tree, int data) {

    //define the node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    //node's parameters
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    //if root is null then assign the new node to the root
    if (tree->root == NULL) {
        tree->root = new_node;
    } 
    else {
        //Check for each root and if the data are larger than the current
        //assign the current node (to be searched) to the child left node
        //if it's also null then make it a root and assign data to it
        struct Node* current = tree->root;
        struct Node* parent = NULL;
        
        while (true) {
            parent = current;
            if (data < current->data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = new_node;
                    return;
                }
            } 
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = new_node;
                    return;
                }
            }
        }
    }
}

// Search for a node with the given data in the binary tree and return a pointer to that node
struct Node* search(struct BinaryTree* tree, int data) {
    struct Node* current = tree->root;
    //not the target
    while (current != NULL && current->data != data) {
        if (data < current->data) {
            current = current->left; //look in the left node
        } else {
            current = current->right; // look in the right node
        }
    }
    return current; //reached target return
}

// Thread function for inserting random values into the binary tree
void* insert_thread(void* arg) {
    struct BinaryTree* tree = (struct BinaryTree*)arg;
    int i;
    for (i = 0; i < 10; i++) {
        int value = rand() % 100;
        printf("Inserting node: %d\n", value);
        insert_node(tree, value);
        printf("Tree after insertion:\n");
        trav_order(tree->root);
        printf("\n\n");
    }
    pthread_exit(NULL);
}

// Thread function for searching random values in the binary tree
void* search_thread(void* arg) 
{
    struct BinaryTree* tree = (struct BinaryTree*)arg;

    int i;
    for (i = 0; i < 10; i++) {
        int value = rand() % 100;
        printf("Searching for %d...\n", value);
        struct Node* result = search(tree, value);

        if (result == NULL) {
            printf("%d not found in tree\n\n", value);
        } 
        else {
            printf("%d found in tree\n\n", value);
        }
    }
    pthread_exit(NULL);
}

// Helper function to print spaces
void print_spaces(int count) {

    for (int i = 0; i < count; i++) {
        printf(" ");
    }
}

// Recursive function to print binary tree as a tree structure
void print_tree(struct Node* node, int level) {
    if (node != NULL) {
        print_tree(node->right, level + 1);

        int i;
        for (i = 0; i < level; i++) {
            printf("\t");
        }
        printf("%d\n", node->data);

        print_tree(node->left, level + 1);
    }
}

int main() {
    // Initialize the binary tree
    struct BinaryTree tree;
    tree.root = NULL;

    // Initialize the random seed
    srand(time(NULL));

    // Create the insert thread
    pthread_t insert_thread_id;
    if (pthread_create(&insert_thread_id, NULL, insert_thread, (void*)&tree)) {
        fprintf(stderr, "Error creating insert thread\n");
        return 1;
    }

    // Create the search thread
    pthread_t search_thread_id;
    if (pthread_create(&search_thread_id, NULL, search_thread, (void*)&tree)) {
        fprintf(stderr, "Error creating search thread\n");
        return 1;
    }

    // Wait for the insert and search threads to finish
    pthread_join(insert_thread_id, NULL);
    pthread_join(search_thread_id, NULL);

    print_tree(tree.root, 0);

    return 0;
}
